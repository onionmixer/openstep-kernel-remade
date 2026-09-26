# `_vm_object_special` indirect callback의 `_smmap` 전달 경계

## 범위

Open item 1의 object 간접 호출과 runtime address-table writer 경계를 원본 바이트로
연결했다. Export label상 `_vm_object_special`인 `0x0017c17c`의 유일한 direct caller와
유일한 indirect CALL을 조사했다. Export 이름은 인벤토리용 가설이며, 아래 결론은 명령과
dataflow에만 근거한다.

## 직접 caller와 callback argument

`0x0017c218 CALL EDX`의 target register는 바로 전 `0x0017c215 MOV EDX,[EBP+0xc]`에서
온다. 이 함수의 direct `CALL rel32` caller는 하나이며,
`0x00107007 CALL 0x0017c17c`이다. 그 caller는 export label상 `_smmap`이다.

이 call 바로 전의 Python 계산된 5개 PUSH 중 ESI는 끝에서 두 번째다.
따라서 callee의 `[EBP+0xc]`와 일치하는 stack argument는
`0x00107001 PUSH ESI`이다. 즉 원본의 이 direct edge는 ESI에 담긴 callback 값을
`CALL EDX`까지 전달하려고 구성되어 있다.

## cdevsw slot과의 정적 연결

같은 `_smmap` body는 더 앞에서
`0x00106f65 MOV ESI,[EDX*4+0x001e2f58]`를 실행한다.
152차가 원본 Mach-O data와 명령으로 확인한 대로 `0x001e2f58`은 file-backed
`_cdevsw` base `0x001e2f38`의 `+0x20` slot이며, entry stride는 44 bytes다.
`_smmap`은 `0x00106fae CALL ESI`도 실행하고, 그 뒤 `PUSH ESI`까지 ESI를 명시적으로
쓰는 원본 명령은 없다.

그러나 둘 사이에는 `CALL ESI`가 있다. 그러므로 정적 caller instruction은 동일한 ESI
register를 다음 call argument로 사용하지만, 첫 callback target이 ESI를 보존한다는
runtime/ABI 결론은 이 보고서에서 내리지 않는다.

static image의 43개 `+0x20` slot은 모두 sentinel `0x0010cca4`였고 `_smmap`은 그 값,
`0x0010ccb0`, zero를 CALL 전에 거부한다. Runtime에서는
`0x001a9d12` (`_IOAddToCdevswAt`)와 `0x001a9dce` (`_IOAddToCdevsw`)가 이 slot을 쓰며,
`_IORemoveFromCdevsw`는 11-dword default template을 entry에 복사한다. 따라서
object-special indirect target을 runtime cdevsw registration과 동일하다고 확정할 수는
없지만, 원본 정적 register path는 runtime-mutable table slot에서 시작한다.

## 한계

callback target의 보존·타입·실제 runtime 값·selector 경계·table lifetime 및
already-derived entry pointer를 통한 모든 writer는 미확정이다. 이 결과는
`_vm_object_special`의 단 하나의 direct caller edge에 한정한다.

정확한 주소·PUSH 순서·Python 계산값은
[vm-object-special-smmap-callback.json](vm-object-special-smmap-callback.json)에 있다.
