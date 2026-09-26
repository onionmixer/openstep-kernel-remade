# 141차 연속 검토 — `__vm_object_allocate` template copy와 `+0x30` alias writer

원본 `__vm_object_allocate`는 source ESI=`0x001f7360`, destination EDI=second argument를
설정하고 `ECX=0x16; REP MOVSD`를 실행한다. Python 계산상 22 dword는 88 bytes이며
template offset `+0x30`의 4 bytes는 이 copy 범위 안에 있다. 따라서 template의 `+0x30`
값은 이 raw copy로 destination alias `+0x30`에 기록된다.

export direct caller는 5개다: vm object init의 two static-storage calls, wrapper
`_vm_object_allocate`, `_vm_object_copy`, `_vm_object_shadow`다. wrapper는 zone allocation
result ESI를 second argument로 전달하고 EAX=ESI로 반환한다.

이는 copy width/source/destination register와 direct edge의 원시 사실이다. destination
nullability, template field type, all indirect callers, runtime allocation lifetime, and
copy execution count는 확정하지 않는다.

