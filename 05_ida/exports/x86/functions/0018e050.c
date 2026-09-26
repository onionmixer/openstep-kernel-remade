/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18e050. */
int __cdecl thread_set_syscall_return(int a1, int a2)
{
  int v2; // eax
  int result; // eax
  int v4; // edx

  v2 = *(_DWORD *)(*(_DWORD *)(a1 + 40) + 112); /*0x18e05b*/
  if ( v2 ) /*0x18e060*/
  {
    result = v2 + 132; /*0x18e062*/
  }
  else
  {
    v4 = kalloc(0xE0u); /*0x18e076*/
    *(_DWORD *)(*(_DWORD *)(a1 + 40) + 112) = v4; /*0x18e07b*/
    result = v4 + 132; /*0x18e07e*/
    qmemcpy((void *)(v4 + 132), &unk_1D15E0, 0x5Cu); /*0x18e091*/
    *(_DWORD *)(v4 + 196) = 512; /*0x18e093*/
    *(_WORD *)(v4 + 192) = 99; /*0x18e09d*/
    *(_WORD *)(v4 + 204) = 107; /*0x18e0a6*/
    *(_WORD *)(v4 + 144) = 107; /*0x18e0af*/
    *(_WORD *)(v4 + 140) = 107; /*0x18e0b8*/
    *(_WORD *)(v4 + 136) = 0; /*0x18e0c1*/
    *(_WORD *)(v4 + 132) = 0; /*0x18e0ca*/
  }
  *(_DWORD *)(result + 44) = a2; /*0x18e0d6*/
  return result; /*0x18e0dc*/
}
