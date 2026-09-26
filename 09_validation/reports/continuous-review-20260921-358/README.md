# 358차 정적 검토 — 원본 추출 Objective-C IMP와 full-pass5 함수 주소 대조

원본 바이너리에서 추출된 objc.json의 1,137개 메서드 IMP를 full-pass5 functions.json 주소 집합과 Python으로 대조했다. 메서드 IMP 중 함수 분석 단위에 없는 주소는 0개다.

objc.json에는 과거 추출 상태의 missing_ghidra_method_entries 5개가 보존돼 있다. NXConditionLock init, IONetbufQueue init, IODisk completeTransfer:withStatus:actualLength:, IODirectDevice isPCIPresent, List initialize의 다섯 IMP도 현재 full-pass5 함수 주소에 모두 존재한다. 따라서 이 목록은 현재 pass의 함수 누락이 아니라 이전 인벤토리 상태 기록이다.

메서드 owner·selector·types 문자열은 이 감사에서 원본 ABI나 소스 선언의 확정 근거로 사용하지 않는다.
