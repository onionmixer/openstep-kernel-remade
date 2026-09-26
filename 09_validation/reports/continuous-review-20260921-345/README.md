# 345차 정적 검토 — Removing unreachable block 경고의 함수 body 소유권 감사

정확히 Removing unreachable block 형식인 538개 경고 인스턴스를 Python으로 다시 집계했다. 43개 경고 레코드에서 발생했으며, 모든 대상 VA는 full-pass5 전체 함수 body 중 정확히 하나에 속한다.

73개는 경고를 낸 함수 body 안에 있고, 465개는 analysis fragment가 가리키는 다른 함수 body 안에 있다. 후자의 465개는 전체 내보내기에서 코드 body 소유자가 없는 주소가 아니라 함수 분할 경계다.

이 감사는 decompiler가 제거한 블록의 실행 가능성이나 런타임 도달성을 판정하지 않는다.
