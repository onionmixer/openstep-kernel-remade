/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x192790. */
int __cdecl unix_syscall(int a1)
{
  int v1; // ecx
  char v2; // dl
  unsigned __int16 v3; // cx
  unsigned __int16 v4; // ax
  int v5; // edx
  int v6; // eax
  int v8; // [esp+4h] [ebp-30h]
  int v9; // [esp+Ch] [ebp-28h]
  void (**v10)(void); // [esp+20h] [ebp-14h]
  int v11; // [esp+24h] [ebp-10h]
  thread_act_t v12; // [esp+28h] [ebp-Ch]

  v12 = active_threads; /*0x1927a9*/
  v9 = 0; /*0x1927ac*/
  v1 = *(_DWORD *)(active_threads + 40); /*0x1927b3*/
  v2 = *(_BYTE *)(v1 + 240); /*0x1927b6*/
  if ( (v2 & 1) != 0 ) /*0x1927bf*/
  {
    *(_BYTE *)(v1 + 240) = v2 & 0xFE; /*0x1927c4*/
    *(_DWORD *)(a1 + 64) |= 0x100u; /*0x1927cd*/
  }
  v11 = *(_DWORD *)(v12 + 132); /*0x1927dd*/
  *(_DWORD *)v11 = a1; /*0x1927e3*/
  *(_BYTE *)(dword_1E875C + 104) = 0; /*0x19280b*/
  v3 = *(_WORD *)(a1 + 44); /*0x192812*/
  v8 = *(_DWORD *)(a1 + 68) + 4; /*0x192823*/
  if ( nsysent <= v3 ) /*0x19282f*/
    v10 = (void (**)(void))&unk_1DA22C; /*0x192840*/
  else
    v10 = (void (**)(void))((char *)&sysent + 8 * v3); /*0x192838*/
  if ( v10 == (void (**)(void))&sysent ) /*0x19284e*/
  {
    v4 = fuword(v8); /*0x192854*/
    v8 += 4; /*0x19285f*/
    if ( nsysent <= v4 ) /*0x192872*/
      v10 = (void (**)(void))&unk_1DA22C; /*0x192880*/
    else
      v10 = (void (**)(void))((char *)&sysent + 8 * v4); /*0x19287b*/
  }
  v5 = 4 * *(__int16 *)v10; /*0x19288d*/
  if ( v5 ) /*0x192893*/
  {
    v6 = copyin(v8, v11 + 4, v5); /*0x1928a1*/
    v9 = v6; /*0x1928a6*/
    if ( v6 ) /*0x1928ae*/
    {
      *(_DWORD *)(a1 + 44) = v6; /*0x1928b3*/
      *(_BYTE *)(a1 + 64) |= 1u; /*0x1928b9*/
      thread_exception_return(); /*0x1928bd*/
    }
  }
  *(_DWORD *)(v11 + 96) = 0; /*0x1928c5*/
  *(_DWORD *)(v11 + 100) = *(_DWORD *)(a1 + 36); /*0x1928d2*/
  if ( setjmp((int *)(v11 + 40)) ) /*0x1928d9*/
  {
    if ( !*(_BYTE *)(v11 + 104) && *(_BYTE *)(v11 + 105) != 2 ) /*0x1928f2*/
      return unix_syscall_return(4); /*0x1928fb*/
  }
  else
  {
    *(_BYTE *)(v11 + 105) = 3; /*0x192903*/
    *(_BYTE *)(v11 + 112) = 0; /*0x19290a*/
    *(_DWORD *)(v11 + 108) = 0; /*0x192911*/
    v10[1](); /*0x19291e*/
    v9 = *(char *)(v11 + 104); /*0x192927*/
  }
  return unix_syscall_return(v9); /*0x192933*/
}
