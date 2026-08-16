package EtherHack.features;

import java.util.List;

public final class AutoAimTargetSelectorTest {
    private AutoAimTargetSelectorTest() {
    }

    public static void main(String[] args) {
        selectsTheTargetClosestToTheAimDirection();
        usesDistanceAsTheTieBreaker();
        rejectsInvalidTargets();
        leavesAimUnchangedWhenNoTargetQualifies();
    }

    private static void selectsTheTargetClosestToTheAimDirection() {
        var centered = candidate("centered", 10.0F, 0.0F, 0.0F, true, false, true, true);
        var nearerButOffAxis = candidate("off-axis", 4.0F, 2.0F, 0.0F, true, false, true, true);

        String selected = AutoAimTargetSelector.select(
                        List.of(nearerButOffAxis, centered), 1.0F, 0.0F, 15.0F, 0.70F)
                .orElseThrow()
                .target();

        require("centered".equals(selected), "Auto aim must prefer the target closest to the current reticle direction");
    }

    private static void usesDistanceAsTheTieBreaker() {
        var far = candidate("far", 12.0F, 0.0F, 0.0F, true, false, true, true);
        var near = candidate("near", 5.0F, 0.0F, 0.0F, true, false, true, true);

        String selected = AutoAimTargetSelector.select(
                        List.of(far, near), 1.0F, 0.0F, 15.0F, 0.70F)
                .orElseThrow()
                .target();

        require("near".equals(selected), "Equally aligned targets must be ordered by distance");
    }

    private static void rejectsInvalidTargets() {
        var valid = candidate("valid", 8.0F, 0.0F, 0.0F, true, false, true, true);
        var dead = candidate("dead", 2.0F, 0.0F, 0.0F, false, false, true, true);
        var fakeDead = candidate("fake-dead", 2.0F, 0.0F, 0.0F, true, true, true, true);
        var hidden = candidate("hidden", 2.0F, 0.0F, 0.0F, true, false, false, true);
        var neutral = candidate("neutral", 2.0F, 0.0F, 0.0F, true, false, true, false);
        var otherFloor = candidate("other-floor", 2.0F, 0.0F, 1.0F, true, false, true, true);
        var tooFar = candidate("too-far", 16.0F, 0.0F, 0.0F, true, false, true, true);
        var behind = candidate("behind", -2.0F, 0.0F, 0.0F, true, false, true, true);

        String selected = AutoAimTargetSelector.select(
                        List.of(dead, fakeDead, hidden, neutral, otherFloor, tooFar, behind, valid),
                        1.0F, 0.0F, 15.0F, 0.70F)
                .orElseThrow()
                .target();

        require("valid".equals(selected), "Auto aim must only select live, visible, hostile targets in range and view");
    }

    private static void leavesAimUnchangedWhenNoTargetQualifies() {
        var hidden = candidate("hidden", 3.0F, 0.0F, 0.0F, true, false, false, true);

        require(AutoAimTargetSelector.select(
                        List.of(hidden), 1.0F, 0.0F, 15.0F, 0.70F).isEmpty(),
                "Auto aim must report no target instead of inventing an aim direction");
        require(AutoAimTargetSelector.select(
                        List.of(), 0.0F, 0.0F, 15.0F, 0.70F).isEmpty(),
                "A zero-length aim vector must not select a target");
    }

    private static AutoAimTargetSelector.Candidate<String> candidate(
            String target,
            float deltaX,
            float deltaY,
            float deltaZ,
            boolean alive,
            boolean fakeDead,
            boolean visible,
            boolean hostile) {
        return new AutoAimTargetSelector.Candidate<>(
                target, deltaX, deltaY, deltaZ, alive, fakeDead, visible, hostile);
    }

    private static void require(boolean condition, String message) {
        if (!condition) {
            throw new AssertionError(message);
        }
    }
}
