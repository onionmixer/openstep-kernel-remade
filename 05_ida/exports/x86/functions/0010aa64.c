/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10aa64. */
int __cdecl rpsleep(void (__cdecl *a1)(int, int), int a2, int a3, const char *a4, const char *a5)
{
  char v5; // al
  int v7; // [esp+0h] [ebp-3Ch]
  _BYTE v8[56]; // [esp+4h] [ebp-38h] BYREF

  v7 = 1; /*0x10aa6a*/
  v5 = *(_BYTE *)(dword_1E875C + 112); /*0x10aa77*/
  if ( v5 >= 0 )
  {
    *(_BYTE *)(dword_1E875C + 112) = v5 | 0x80; /*0x10aa80*/
    uprintf("[%s: %s%s, pausing ...]\r\n", (const char *)(active_u + 8), a4, a5);
  }
  bcopy((const void *)(dword_1E875C + 40), v8, 0x38u); /*0x10aab0*/
  if ( setjmp((int *)(dword_1E875C + 40)) ) /*0x10aabe*/
    v7 = 0; /*0x10aadc*/
  else
    a1(a2, a3); /*0x10aad5*/
  bcopy(v8, (void *)(dword_1E875C + 40), 0x38u); /*0x10aaf2*/
  if ( *(char *)(dword_1E875C + 112) >= 0 ) /*0x10ab03*/
    rpcont(); /*0x10ab05*/
  return v7; /*0x10ab0d*/
}
