# `_vm_page_init` template copy의 정적 caller·pointer-table 부재

Open item 1의 page template 수명 경계에서, template copy 함수로 export된
`_vm_page_init` (`0x0017b134`)의 static call 및 address-table 흔적을 원본 전체에서
확인했다. `0x0017b143 MOV ESI,0x001f7440`, `0x0017b14b MOV ECX,0xc`,
`0x0017b150 REP MOVSD`가 48-byte template copy를 수행한다는 기존 사실을 전제로 한다.

full-pass5의 5,253개 exported function body fragment를 raw Capstone decode한 결과,
`CALL rel32`가 `0x0017b134`를 직접 목표로 하는 site는 0개다. `_vm_page_init` body
자체에도 register/memory operand `CALL`은 0개다.

entry address `0x0017b134`의 little-endian 4-byte pattern은 원본 파일에서 한 번만
나타나며, file offset 1,057,900이다. Python으로 Mach-O `LC_SYMTAB`을 parse하면 nlist
범위는 1,015,808부터 1,060,820 직전까지이므로 이 occurrence는 nlist 안에 있다.
file-backed `__text`, `__const`, `__data`, `__OBJC` 영역에는 해당 pattern이 없다.
따라서 이 원본 static image에는 `_vm_page_init` entry를 직접 담은 file-backed
function-pointer table이 발견되지 않았다.

이것은 page-init copy가 실행되지 않는다는 결론이 아니다. computed address, BSS/runtime
writer, indirect caller, non-export code, loader 초기화와 runtime call 횟수는 이 정적
검사에서 여전히 미확정이다.

원시 검사와 Python 수치는
[page-init-static-edge-audit.json](page-init-static-edge-audit.json)에 기록했다.
