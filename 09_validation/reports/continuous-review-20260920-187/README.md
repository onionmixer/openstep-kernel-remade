# object callback caller의 44-byte indexed table writer·reset path

176차에서 callback pointer의 source로 확인한 `0x001e2f58 + 44*byte_value` table field의
writer/reset path를 원본 명령으로 추적했다. raw data의 dword `0x001e369c`는 43이며,
base `0x001e2f38 + 43*44`가 정확히 `0x001e369c`이다. 따라서 reader field
`0x001e2f58`은 base의 `+0x20`이고 44-byte cell stride와 일치한다.

`_IOAddToCdevswAt` label의 raw body는 index에서 `11*index*4`를 계산해
`EDX=0x001e2f38+44*index`를 만든다. index가 `[0,43)`인 path에서
`0x001a9d12 MOV [EDX+0x20],ECX`를 수행하며 ECX는 stack argument `[EBP+0x2c]`에서
온다. 같은 body는 cell의 나머지 10 dword도 argument로 쓴다. index가 -1이면 43 cell을
44 bytes씩 비교해 후보 index를 찾은 뒤 같은 range gate를 적용한다.

`_IORemoveFromCdevsw` label은 supplied index에서 같은 address를 계산하고,
`0x001a9e01 MOV ESI,0x001e5100; ECX=0xb; REP MOVSD`로 11 dword를 해당 cell에 복사한다.
따라서 reader field `+0x20`도 reset copy 범위에 포함된다. 원본 `CALL rel32` inventory에서
add target의 direct site는 `0x001a453e` 하나, remove target의 direct site는 `0x001a46b9`
하나다.

이는 callback field가 file image 고정값만은 아니며 raw indexed setter/reset writer가 있음을
보인다. runtime call timing, selector/index value, argument target, table initialisation 순서,
additional computed/non-export writer 및 callback target lifetime은 아직 확정하지 않는다.
export label은 API 의미 증거로 사용하지 않았다.

table 산식·bound·writer/reset instruction은 [callback-indexed-table-writer-reset.json](callback-indexed-table-writer-reset.json)에 기록했다.
