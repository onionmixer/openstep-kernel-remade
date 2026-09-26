# `_vm_map_deallocate` 37개 direct caller의 EAX 경계

Open item 2의 deallocate caller-wide 검토를 116차의 3-instruction 창보다 확장했다.
`0x001747d8` direct `CALL rel32` 37개에서 caller export body의 direct CFG를 따라,
호출 전의 EAX가 처음 읽히거나 overwrite·RET·후속 CALL·loop back-edge에 이르는 곳을
Python/Capstone으로 찾았다.

37개 site 중 old EAX를 읽는 instruction은 0개였다. 종착 path는 overwrite 22개, RET
13개, subsequent CALL 6개, loop back-edge 5개다. path 수와 site 수는 다르므로 합계를
동적 실행 횟수로 해석하지 않는다.

RET 13개와 loop 5개는 caller body 안에서 EAX가 새 status가 되지 않았다는 뜻일 뿐이다.
RET는 upper caller로 레지스터가 통과할 수 있고, loop는 재진입 뒤의 상태를 이 분석만으로
확정할 수 없다. 후속 CALL 6개도 그 callee가 EAX를 관찰하지 않는다는 뜻이 아니다.
따라서 원본은 이 direct edges에 즉시 `TEST EAX` rollback 분기를 보이지 않지만, 전체
transaction rollback이나 간접/computed caller 부재를 증명하지 않는다.

상세 site별 첫 CFG 경계와 Python 집계는
[map-deallocate-eax-cfg.json](map-deallocate-eax-cfg.json)에 기록했다.
