# 131차 연속 검토 — `_vm_map_copy` status 경로와 cleanup lock 순서

원본 `_vm_map_copy`는 lock 획득 뒤 local status `-0x24`를 0으로 설정한다. boundary
비교 세 개가 `0x00176a58`의 status 1 write로, helper `0x001749c4`의 EAX test가
`0x00176a94`의 status 3 write로, entry-state scan의 세 조건이 `0x00176cd4`의 status 2
write로 연결된다. 세 write는 모두 `0x00177a31` common cleanup으로 jump한다.

cleanup은 local `-0x28`을 검사해 0이 아니면 `0x00176164` call을 실행한다. 이후 second
map argument에 `0x0015b73c` call을 하고, first/second map pointer가 다를 때만 first
argument에 같은 call을 한다. 끝에서 local status를 EAX로 반환한다.

이는 raw control flow·call order의 정적 관측이다. status 수치의 오류명, `0x001749c4`와
`0x00176164` helper 내부 의미, cleanup 이전 모든 side effect의 역전 가능성, runtime
lock ownership은 이 범위에서 확정하지 않는다.

