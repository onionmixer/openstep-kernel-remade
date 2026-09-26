# 디컴파일러 한계

- table record와 callback graph의 struct type은 확정하지 않았다. 본문에서 register가
  어떻게 pointer를 전달하는지와 load offset만 기록했다.
- shutdown에서 table clear가 보이지 않는다는 것은 index 재사용 또는 use-after-free의
  확정 증거가 아니다. 해당 결과는 별도 caller·allocator 분석이 필요하다.
