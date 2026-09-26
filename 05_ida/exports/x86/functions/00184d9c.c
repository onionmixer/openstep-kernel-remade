/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x184d9c. */
int __cdecl sub_184D9C(int a1, __int16 a2, __int16 a3, int a4, int a5, char *__src, char *a7, int a8)
{
  int v8; // ebx
  _UNKNOWN **v9; // eax
  int v11; // ebx
  __int16 v12; // ax
  __int16 v13; // ax

  if ( !byte_1E7589 ) /*0x184dbf*/
  {
    lock_init(&unk_1E758C, 1); /*0x184dc8*/
    byte_1E7589 = 1; /*0x184dcd*/
  }
  if ( dword_1E13EC ) /*0x184dde*/
  {
    if ( a1 ) /*0x184e76*/
    {
      return 4; /*0x184e78*/
    }
    else
    {
      v11 = kalloc(0x84u); /*0x184e8e*/
      qmemcpy((void *)v11, &unk_1E1410, 0x70u); /*0x184e9d*/
      *(_BYTE *)(v11 + 3) = 1; /*0x184ea2*/
      *(_DWORD *)(v11 + 4) = 132; /*0x184ea6*/
      *(_DWORD *)(v11 + 16) = dword_1E13EC; /*0x184eb3*/
      *(_DWORD *)(v11 + 28) = a5; /*0x184eb9*/
      *(_DWORD *)(v11 + 32) = 0; /*0x184ebc*/
      *(_DWORD *)(v11 + 40) = a8; /*0x184ec6*/
      strcpy((char *)(v11 + 48), __src); /*0x184ed1*/
      *(_BYTE *)(v11 + 112) = 2; /*0x184ed9*/
      *(_BYTE *)(v11 + 113) = 32; /*0x184edd*/
      v12 = *(_WORD *)(v11 + 114) & 0xF000; /*0x184ee5*/
      LOBYTE(v12) = 2; /*0x184ee9*/
      *(_WORD *)(v11 + 114) = v12; /*0x184eeb*/
      *(_BYTE *)(v11 + 115) = *(_BYTE *)(v11 + 115) & 0x8F | 0x10; /*0x184ef6*/
      *(_WORD *)(v11 + 116) = a2; /*0x184efd*/
      *(_WORD *)(v11 + 118) = a3; /*0x184f05*/
      *(_BYTE *)(v11 + 120) = 8; /*0x184f09*/
      *(_BYTE *)(v11 + 121) = 8; /*0x184f0d*/
      v13 = *(_WORD *)(v11 + 122) & 0xF000; /*0x184f15*/
      LOBYTE(v13) = 6; /*0x184f19*/
      *(_WORD *)(v11 + 122) = v13; /*0x184f1b*/
      *(_BYTE *)(v11 + 123) = *(_BYTE *)(v11 + 123) & 0x8F | 0x10; /*0x184f26*/
      strcpy((char *)(v11 + 124), a7); /*0x184f31*/
      return msg_send_from_kernel((void *)v11, 1, 0); /*0x184f3e*/
    }
  }
  else
  {
    v8 = kalloc(0x64u); /*0x184deb*/
    *(_DWORD *)(v8 + 8) = a1; /*0x184ded*/
    *(_WORD *)(v8 + 12) = a2; /*0x184df4*/
    *(_WORD *)(v8 + 14) = a3; /*0x184dfc*/
    *(_DWORD *)(v8 + 16) = a4; /*0x184e03*/
    *(_DWORD *)(v8 + 20) = a5; /*0x184e09*/
    *(_DWORD *)(v8 + 96) = a8; /*0x184e0f*/
    strcpy((char *)(v8 + 24), __src); /*0x184e1a*/
    strcpy((char *)(v8 + 88), a7); /*0x184e27*/
    lock_write(&unk_1E758C); /*0x184e31*/
    v9 = off_1E1400[0]; /*0x184e39*/
    if ( off_1E1400[0] == &off_1E13FC ) /*0x184e43*/
      off_1E13FC = (_UNKNOWN *)v8; /*0x184e45*/
    else
      *off_1E1400[0] = (_UNKNOWN *)v8; /*0x184e50*/
    *(_DWORD *)(v8 + 4) = v9; /*0x184e52*/
    *(_DWORD *)v8 = &off_1E13FC; /*0x184e55*/
    off_1E1400[0] = (_UNKNOWN **)v8; /*0x184e5b*/
    lock_done(&unk_1E758C); /*0x184e66*/
    return 0; /*0x184e6b*/
  }
}
