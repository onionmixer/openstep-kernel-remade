/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16d20c. */
void __noreturn notify_server_loop()
{
  task_t v0; // ebx
  int v1; // eax
  kern_return_t v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  _DWORD *v7; // ebx
  int v8; // eax
  int v9; // eax

  *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 80) = 1; /*0x16d218*/
  v0 = *(_DWORD *)(active_threads + 12); /*0x16d224*/
  v1 = port_allocate(*(_DWORD *)(v0 + 136), &dword_1E726C); /*0x16d233*/
  if ( v1 ) /*0x16d23d*/
    sub_16D3C8(v1, aPortAllocate); /*0x16d245*/
  get_kern_port(v0, dword_1E726C, &special_port); /*0x16d25a*/
  v2 = task_set_special_port(v0, 2, special_port); /*0x16d269*/
  if ( v2 ) /*0x16d273*/
    sub_16D3C8(v2, aTaskSetSpecial); /*0x16d27b*/
  v3 = port_allocate(*(_DWORD *)(v0 + 136), &pn_register_port); /*0x16d28f*/
  if ( v3 ) /*0x16d299*/
    sub_16D3C8(v3, aPortAllocate_0); /*0x16d2a1*/
  get_kern_port(v0, pn_register_port, &pn_register_port_k); /*0x16d2b6*/
  v4 = port_set_allocate(*(_DWORD *)(v0 + 136), &dword_1E7274); /*0x16d2c7*/
  if ( v4 ) /*0x16d2d1*/
    sub_16D3C8(v4, aPortSetAllocat); /*0x16d2d9*/
  v5 = port_set_add(*(_DWORD *)(v0 + 136), dword_1E7274, dword_1E726C); /*0x16d2f6*/
  if ( v5 ) /*0x16d300*/
    sub_16D3C8(v5, aPortSetAdd); /*0x16d308*/
  v6 = port_set_add(*(_DWORD *)(v0 + 136), dword_1E7274, pn_register_port); /*0x16d325*/
  if ( v6 ) /*0x16d32f*/
    sub_16D3C8(v6, aPortSetAdd_0); /*0x16d337*/
  v7 = (_DWORD *)kalloc(0x2000u); /*0x16d349*/
  dword_1E727C = (int)&dword_1E7278; /*0x16d34b*/
  dword_1E7278 = (int)&dword_1E7278; /*0x16d355*/
  while ( 1 )
  {
    v7[3] = dword_1E7274; /*0x16d36a*/
    v7[1] = 0x2000; /*0x16d36d*/
    v8 = msg_receive(v7, 0, 0); /*0x16d379*/
    if ( v8 )
    {
      printf("notify_server_loop: msg_receive error (%d)\n", v8);
    }
    else
    {
      v9 = v7[3]; /*0x16d398*/
      if ( pn_register_port == v9 )
      {
        sub_16D3EC(v7); /*0x16d3a4*/
      }
      else if ( dword_1E726C == v9 )
      {
        sub_16D454(v7); /*0x16d3b5*/
      }
      else
      {
        printf("notify_server_loop: BOGUS msg_local_port\n");
      }
    }
  }
}
