/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1859dc. */
void __noreturn sub_1859DC()
{
  int v0; // ebx
  int v1; // eax
  int v2; // eax
  _UNKNOWN **v3; // eax
  void (__cdecl *v4)(void *, void *, _DWORD); // edx
  _UNKNOWN **v5; // [esp+4h] [ebp-4h]

  v0 = kalloc(0x2000u); /*0x1859ed*/
  while ( 1 )
  {
    while ( 1 ) /*0x1859fa*/
    {
      *(_DWORD *)(v0 + 12) = dword_1E13F8; /*0x1859fa*/
      *(_DWORD *)(v0 + 4) = 0x2000; /*0x1859fd*/
      v1 = msg_receive((void *)v0, 0, 0); /*0x185a09*/
      if ( !v1 ) /*0x185a13*/
        break; /*0x185a13*/
      printf(aVolThreadMsgRe, v1); /*0x185a1b*/
    }
    v2 = *(_DWORD *)(v0 + 20); /*0x185a20*/
    if ( v2 == 65 )
    {
      sub_18585C(v0); /*0x185a6d*/
    }
    else if ( v2 == 855 )
    {
      v3 = sub_1857FC(*(void **)(v0 + 28)); /*0x185a33*/
      if ( v3 ) /*0x185a3d*/
      {
        v4 = (void (__cdecl *)(void *, void *, _DWORD))v3[3]; /*0x185a3f*/
        if ( v4 ) /*0x185a44*/
        {
          v5 = v3; /*0x185a52*/
          v4(v3[4], v3[2], *(_DWORD *)(v0 + 32)); /*0x185a55*/
          v3 = v5; /*0x185a5a*/
        }
        kfree(v3, 20); /*0x185a60*/
      }
    }
    else
    {
      printf("vol_thread: bogus message rec'd (msg_id = %d)\n", *(_DWORD *)(v0 + 20));
    }
  }
}
