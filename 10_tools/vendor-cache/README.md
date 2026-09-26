# IDA 도구 후보 source·검증 binary cache

이 디렉터리는 원본 OPENSTEP kernel 분석 입력과 분리된 도구 후보의 재현용 Git bundle 및
검증된 headless plugin binary를 둔다. 어느 파일도 kernel 원본·reference kernel source·분석 결과가 아니다.

| Bundle | 고정 commit | Python SHA-256 |
|---|---|---|
| `GhidraDec-35afec3d588407de8e2aae5330f26dea857c26bd.bundle` | `35afec3d588407de8e2aae5330f26dea857c26bd` | `a5d1a28f13efda7545a08933cb63e222900f3eafd7f938e622388c61c6ddb11b` |
| `ida-sdk-v9.3-d5db59ab4e9d2ae92038e9520082affd0da6fe20.bundle` | `d5db59ab4e9d2ae92038e9520082affd0da6fe20` | `bc8894fd15d19ec43a14e6538ab55e06cde53f80fc375c6d8161dd510ad4c3e1` |
| `ghidradec64-ida93-linux-ea64-194f39a774f7d5a8fc13cfe5f03dc24dff2bc6f675dda28603d86d208f500686.so` | GhidraDec `35afec3d588407de8e2aae5330f26dea857c26bd`, IDA SDK v9.3 `d5db59ab4e9d2ae92038e9520082affd0da6fe20` | `194f39a774f7d5a8fc13cfe5f03dc24dff2bc6f675dda28603d86d208f500686` |
| `ghidradec64-ida93-linux-ea64-54c15247fefd2dd6753f665bffe5669ba65533b5ebe492ee882285a29815a228.so` | same pinned GhidraDec/IDA SDK, plus [`ghidradec-headless-slice-output.patch`](../patches/ghidradec-headless-slice-output.patch) | `54c15247fefd2dd6753f665bffe5669ba65533b5ebe492ee882285a29815a228` |
| `ghidradec64-ida93-linux-ea64-ea399a6e7ac180bf4adafc74f08cf73f4d3862c786de67db83fe39e234f4bb8b.so` | previous headless changes plus include-skipped and import-status output | `ea399a6e7ac180bf4adafc74f08cf73f4d3862c786de67db83fe39e234f4bb8b` |
| `ghidradec64-ida93-linux-ea64-42d7343debf731ca749e09f6e7c010eff94230c194928509e56bcc46f3e9fea2.so` | previous headless changes plus explicit address selection and batch mapped-symbol-hole safety mode | `42d7343debf731ca749e09f6e7c010eff94230c194928509e56bcc46f3e9fea2` |

각 bundle은 `/tmp` clone과 source tree marker까지 검증했다. binary는 initial basic batch probe failure 뒤
batch-output·live-callback 및 전역 headless m68k·SPARC probe에서 C output을 확인한 artifact다. 전역 설치와
Python hash 검증 기록은 [global installation assessment](../../09_validation/reports/multiarch-input-20260921/ghidradec-global-install-20260922/README.md)에 있다.
