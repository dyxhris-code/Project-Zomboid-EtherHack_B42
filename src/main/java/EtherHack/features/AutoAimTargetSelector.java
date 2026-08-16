package EtherHack.features;

import java.util.Collection;
import java.util.Comparator;
import java.util.Objects;
import java.util.Optional;

public final class AutoAimTargetSelector {
    private static final float MAX_LEVEL_DELTA = 0.25F;
    private static final float MIN_DIRECTION_LENGTH_SQUARED = 0.0001F;

    private AutoAimTargetSelector() {
    }

    public static <T> Optional<Candidate<T>> select(
            Collection<Candidate<T>> candidates,
            float aimX,
            float aimY,
            float maxDistance,
            float minimumDot) {
        if (candidates == null
                || candidates.isEmpty()
                || !Float.isFinite(aimX)
                || !Float.isFinite(aimY)
                || !Float.isFinite(maxDistance)
                || maxDistance <= 0.0F) {
            return Optional.empty();
        }

        float aimLengthSquared = aimX * aimX + aimY * aimY;
        if (aimLengthSquared < MIN_DIRECTION_LENGTH_SQUARED) {
            return Optional.empty();
        }

        float inverseAimLength = 1.0F / (float)Math.sqrt(aimLengthSquared);
        float normalizedAimX = aimX * inverseAimLength;
        float normalizedAimY = aimY * inverseAimLength;
        float maximumDistanceSquared = maxDistance * maxDistance;

        return candidates.stream()
                .filter(Objects::nonNull)
                .filter(candidate -> isEligible(candidate, maximumDistanceSquared))
                .map(candidate -> score(candidate, normalizedAimX, normalizedAimY))
                .filter(scored -> scored.dot() >= minimumDot)
                .max(Comparator.comparingDouble(ScoredCandidate<T>::dot)
                        .thenComparing(Comparator.comparingDouble(ScoredCandidate<T>::distanceSquared).reversed()))
                .map(ScoredCandidate::candidate);
    }

    private static boolean isEligible(Candidate<?> candidate, float maximumDistanceSquared) {
        if (candidate.target() == null
                || !candidate.alive()
                || candidate.fakeDead()
                || !candidate.visible()
                || !candidate.hostile()
                || !Float.isFinite(candidate.deltaX())
                || !Float.isFinite(candidate.deltaY())
                || !Float.isFinite(candidate.deltaZ())
                || Math.abs(candidate.deltaZ()) > MAX_LEVEL_DELTA) {
            return false;
        }

        float distanceSquared = candidate.deltaX() * candidate.deltaX()
                + candidate.deltaY() * candidate.deltaY();
        return distanceSquared >= MIN_DIRECTION_LENGTH_SQUARED
                && distanceSquared <= maximumDistanceSquared;
    }

    private static <T> ScoredCandidate<T> score(
            Candidate<T> candidate, float normalizedAimX, float normalizedAimY) {
        float distanceSquared = candidate.deltaX() * candidate.deltaX()
                + candidate.deltaY() * candidate.deltaY();
        float inverseDistance = 1.0F / (float)Math.sqrt(distanceSquared);
        float dot = candidate.deltaX() * inverseDistance * normalizedAimX
                + candidate.deltaY() * inverseDistance * normalizedAimY;
        return new ScoredCandidate<>(candidate, dot, distanceSquared);
    }

    public record Candidate<T>(
            T target,
            float deltaX,
            float deltaY,
            float deltaZ,
            boolean alive,
            boolean fakeDead,
            boolean visible,
            boolean hostile) {
    }

    private record ScoredCandidate<T>(Candidate<T> candidate, float dot, float distanceSquared) {
    }
}
