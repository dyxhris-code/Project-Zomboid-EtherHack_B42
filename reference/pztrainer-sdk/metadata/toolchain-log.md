# 本次静态分析工具记录

日期：2026-08-16（北京时间）

- ILSpy 10.1.0.8386：已登记在 `D:\Develope\Tools\ilspycmd`；确认样本没有托管元数据。
- Radare2 6.2.0：`D:\Develope\Tools\radare2-6.2.0`；官方下载包 SHA-256：`ADB1FFD158066EA41316FA33B6D23B362AA9258DF800721F7D15A42EEFDD9202`。
- r2ghidra 6.2.0 插件：`D:\Develope\Tools\r2ghidra-6.2.0`；官方下载包 SHA-256：`0D45EA9E3B3E3CF336366104704B49F75B06B51570245B1902F8AACAFA732355`。
- 本次实际使用 Radare2 内置 `pdc`，未加载 DLL、未附加进程、未安装驱动。
- Ghidra 官方压缩包曾尝试续传到 `D:\Develope\Installers\ghidra_12.1.2_PUBLIC_20260605.zip`；链路过慢而中止，保留可续传部分，未解压、未加入 PATH。

## 2026-08-17 update

- The Ghidra 12.1.2 archive completed successfully and passed ZIP directory validation.
- Archive SHA-256: `B62E81A0390618466C019C60D8C2F796CED2509C4C1AEA4A37644A77272CF99D`.
- Installed under `D:\Develope\Tools\ghidra_12.1.2_PUBLIC` without changing the system PATH.
- Imported `pztrainer.dll` into an isolated Headless project under `build\ghidra-project` and generated the semantic export under `analysis\ghidra`.
