/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x124cb8. */
char *__usercall sub_124CB8@<eax>(char *a1@<ebx>, int a2, void *a3)
{
  char *i; // edx
  char __dst[32]; // [esp+10h] [ebp-20h] BYREF

  strcpy(__dst, *(const char **)a2); /*0x124cce*/
  for ( i = __dst; *i; ++i ) /*0x124cdc*/
    ; /*0x124ce0*/
  *i = *(_WORD *)(a2 + 8) + 48; /*0x124cec*/
  i[1] = 0; /*0x124cee*/
  bcopy(a3, &__dst[16], 0x10u); /*0x124cff*/
  qmemcpy(a1, __dst, 0x20u); /*0x124d0d*/
  return a1; /*0x124d15*/
}
