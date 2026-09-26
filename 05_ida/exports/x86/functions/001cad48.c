/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cad48. */
void __cdecl __noreturn NXDefaultExceptionRaiser(int a1, int a2, int a3)
{
  thread_act_t v3; // edx
  int **v4; // eax
  int **v5; // ebx
  int *v6; // eax
  int v7; // edx

  v3 = current_thread_EXTERNAL(); /*0x1cad56*/
  v4 = (int **)&unk_1E551C; /*0x1cad58*/
  if ( &unk_1E551C ) /*0x1cad5f*/
  {
    while ( v4[4] != (int *)v3 ) /*0x1cad67*/
    {
      v4 = (int **)v4[5]; /*0x1cad70*/
      if ( !v4 ) /*0x1cad75*/
        goto LABEL_5; /*0x1cad75*/
    }
    v5 = v4; /*0x1cad69*/
  }
  else
  {
LABEL_5:
    v5 = (int **)sub_1CA960(v3); /*0x1cad77*/
  }
  while ( 1 ) /*0x1cad84*/
  {
    v6 = *v5; /*0x1cad84*/
    if ( !*v5 ) /*0x1cad84*/
      break; /*0x1cad84*/
    if ( ((unsigned __int8)v6 & 1) == 0 ) /*0x1cadb6*/
    {
      v6[19] = a1; /*0x1cae17*/
      v6[20] = a2; /*0x1cae1a*/
      v6[21] = a3; /*0x1cae20*/
      *v5 = (int *)v6[18]; /*0x1cae26*/
      longjmp(v6, 1); /*0x1cae2b*/
    }
    v7 = (int)&v5[1][3 * (((int)v6 - 1) / 2)]; /*0x1cadcc*/
    *v5 = *(int **)v7; /*0x1cadd1*/
    v5[3] = (int *)((-1431655765 * (v7 - (int)v5[1])) >> 2); /*0x1cadf6*/
    (*(void (__cdecl **)(_DWORD, int, int, int))(v7 + 4))(*(_DWORD *)(v7 + 8), a1, a2, a3); /*0x1cae09*/
  }
  if ( _NXUncaughtExceptionHandler ) /*0x1cad91*/
    _NXUncaughtExceptionHandler(a1, a2, a3); /*0x1cada1*/
  panic("Uncaught exception"); /*0x1cadab*/
}
