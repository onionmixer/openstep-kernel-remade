# 122차 연속 검토 — object template 및 object-family `dword +0x30` writer

## 판정

원본 init sequence는 `0x00178aea MOV DWORD PTR [0x001f7390],0`을 실행한다. Python 계산으로
template base `0x001f7360`과 이 absolute address의 차는 48 bytes (`0x30`)다. 따라서
template의 `+0x30` 위치는 init 원시 명령에서 0으로 설정된다.

`_vm_object`/`__vm_object` 이름군 27개 body fragment 전체에서, displacement `0x30` 및
dword width memory operand를 Python Capstone으로 추출했다. 결과는 access 1개이며
`_vm_object_collapse`의 `0x00179a79 MOV DWORD PTR [ESI+0x30],0` write다. 인접 명령은
같은 ESI의 `+0x28`, `+0x30`, `+0x34`를 순서대로 0으로 쓴다.

이는 template 초기 값과 object-family relative writer의 정적 관측이다. 복사된 template가
항상 어느 concrete object가 되는지, ESI의 전체 provenance, prefix 밖 alias writer 및
runtime 도달 횟수는 이 범위에서 확정하지 않는다.

