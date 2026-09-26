# 291차 정적 검토 — __seterr_reply의 branch·indirect-jump 집계

원본 OPENSTEP x86 mach_kernel의 __seterr_reply(0x00136ae4) 10개 body segment 합계
240바이트를 정적 검토했다. full-pass5 명령 목록의 명령 길이를 원본 바이트와 대조한 결과,
conditional branch는 10개, direct unconditional jump는 16개, raw indirect jump는 1개,
plain RET는 1개다.

raw indirect jump는 0x00136b1d의 ff2485246b1300이다. jump-table entry나 실행 시
선택 target은 확정하지 않는다. 전체 __text의 직접 E8 rel32 target scan은 0x001359de
한 곳의 caller를 확인했다.

집계와 segment hash는
[seterr-reply-branch-inventory.json](seterr-reply-branch-inventory.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
