# 146차 완료 판정 정정 — 열린 항목 1·2는 계속 진행

`continuous-review-20260920-146/COMPLETION.md`의 완료 판정은 철회한다. 107–145차
checkpoint의 무결성은 확인됐지만, 무결성 검증은 분석 범위의 완결성을 증명하지 않는다.

## 원본 근거가 아직 충족하지 못한 요구

### 항목 1

* 108차는 모든 map-entry 생성자와 alias writer의 완전 목록이 아니라고 기록한다.
* 111·122·141차는 object `+0x30`의 alias provenance, prefix 밖 writer, runtime lifetime을
  확정하지 않는다.
* 120·134차는 indirect callback의 writer/table lifetime과 computed address writer를
  확정하지 않는다.
* 126–128차의 전수성은 export body의 static absolute operand에 한정된다. computed store,
  loader/BSS, 비-export 코드, runtime 변경은 그 범위 밖이다.

### 항목 2

* 116·119·124차의 caller inventory는 export가 가진 direct unconditional edge만 다루며,
  indirect/computed caller를 포함하지 않는다.
* 117·118·131차는 helper 내부와 caller별 rollback/lock order 전체를 미확정으로 남긴다.
* 129·130·142차는 shadow/object-copy/fault-copy의 indirect caller와 allocation-failure
  경계를 확정하지 않는다.
* 144차의 128-byte pre-call 창은 특정 두 lock helper의 부재만 보이며 caller-wide lock
  order의 증명이 아니다.

따라서 항목 1·2는 여전히 진행 중이다. 후속 분석은 original `mach_kernel`의 raw bytes와
그 바이너리에서 유도한 export만 사용하고, 계산·집계는 Python으로 수행한다.

## 다음 우선 분석

항목 2의 `_vm_map_deallocate` 37개 direct call site에 대해 caller-body control flow,
lock acquire/release 후보와 rollback/cleanup 분기를 원본에서 확장한다. 이후 computed alias와
indirect edge의 도달 가능 여부를 별도 원문 증거로 좁힌다.
