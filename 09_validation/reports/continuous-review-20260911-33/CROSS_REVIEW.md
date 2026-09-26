# 코딩 전 독립 검토

`/root/vm_contract_review27`에 읽기전용 검토를 요청하고 응답을 받은 뒤 코딩한다.
검토자는 파일/DB를 변경하거나 생산 스크립트를 실행하지 않았다. 의견을 정답으로
간주하지 않고 root가 `00178894`, `0018f7f8`, `0018fa44`, `00190f90` 원본 ASM을
직접 읽고 Python으로 주소·mask·크기·계수를 계산했다.

검토에서 채택한 주의점:

- segment 배열 끝과 count의 인접 관계 및 descriptor 비연속성 확인.
- DATA 끝은 PT 시작이므로 lookup 경계의 예상값을 0으로 일반화하지 않음.
- 두 번째 HW PTE가 dirty여도 대표 DATA를 조회하지만, 이 경우 첫 PTE clear는
  lookup보다 먼저 발생한다. 원본 `18f94c` 반복문을 직접 확인했다.
- 새 prefix는 `setup/before/fault/at_fault/cpu_frame_input/frame_address/injected/
  handler/recorded_heads/writes/after` 및 scenario/실패 상태를 비교한다.
  32의 중간 `points/zero_chunks`는 이번에 다시 수집하지 않는다. 따라서 정확한
  주장은 trace/store/boundary 동등성이며 32 전체 중간 관찰의 신규 재검증이 아니다.
  frozen32의 중간 CPU/zero 관찰은 별도 보존된 근거로 유지한다.
- frozen32 manifest를 먼저 검증하고 JSON의 값을 새 실행 기록에 복사하지 않는다.
- segment/caller 입력 경계에서 dirty PTE·CR3·selector·메타데이터를 변경하지 않는다.
- lookup 인자·raw segment 산술·반환 EAX·실제 clean store의 주소/폭/순서를 연결한다.
- page active/tabled/resident, PT backing wired 상태 보존과 free PT queue 이동을 구분한다.

이는 코딩 전 검토 기록이다. 실행/독립 감사/음성 대조/재현 완료는 각 산출물로 판단한다.

## 코딩 후 별도 검토와 root 재검증

동일 검토자에게 새 runner/audit를 읽기전용으로 검토하도록 요청했다. 제공된 첫 사례의
정상 대조와 deepcopy 훼손(bridge, prefix 쓰기, segment, lookup 반환, PDE 권한,
kernel wire, branch 위장 쓰기)을 검사해 거절됐다고 보고했다. 검토자의 단일사례
결과를 전체 행렬 성공으로 확대하지 않았고 root가 별도의 전체 실행/감사 및 공식
음성 대조 스크립트를 실행했다. 추가 필수 수정 의견은 없었다.

root는 첫 prefix 비교에서 setup의 Python tuple/int-key와 JSON 표현 차이를 발견했다.
독립 Python 비교에서 JSON 표현으로 직렬화하면 모든 필드 값이 같음을 확인한 뒤,
새 관찰값의 JSON 타입만 통일했다. 필드 삭제·정규화 허용 mask·원본 상태 보정은
하지 않았다. 이후 전체 scenario의 비교가 통과했다.

root가 감사 조건에 lookup 경계의 end-pointer CPU, modified/reference descriptor
register와 단계별 attribute, PV 제거 register의 일치를 추가했다. 전체 감사와
대조시험은 최종 코드로 새로 재실행한다. Codex 의견은 독립 CPU/hardware 증거가 아니다.
