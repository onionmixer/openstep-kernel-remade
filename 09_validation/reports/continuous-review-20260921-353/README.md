# 353차 정적 검토 — full-pass5 references.tsv endpoint 범위 감사

references.tsv의 125,531개 레코드를 memory-blocks.json과 Python으로 대조했다. 모든 from 주소는 분석 메모리 블록 안에 있다. 숫자형 to 주소는 85,225개이며 그중 55개가 현재 메모리 블록 밖이다. 나머지 40,306개 대상은 Stack 등의 비숫자 표현이다.

블록 밖 55개는 낮은 주소 범위, 0x00000000의 unconditional call, 0x29232840·0x29232844의 큰 상수형 read 대상 등으로 표현된다. 이 감사는 references.tsv endpoint 표현을 다루며, 해당 주소의 실제 메모리 매핑이나 런타임 접근 가능성을 결론내리지 않는다.
