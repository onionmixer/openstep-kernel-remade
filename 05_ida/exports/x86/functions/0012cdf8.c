/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12cdf8. */
int __cdecl makefh(char *a1, int a2, int a3)
{
  int v4; // ecx
  unsigned __int16 *v5; // edx
  unsigned __int16 v6; // ax
  unsigned __int16 *v7; // [esp+10h] [ebp-4h] BYREF

  if ( (*(int (__cdecl **)(int, unsigned __int16 **))(*(_DWORD *)(a2 + 28) + 100))(a2, &v7) || !v7 ) /*0x12ce23*/
    return 71; /*0x12ce25*/
  v4 = *v7; /*0x12ce30*/
  if ( (unsigned int)**(unsigned __int16 **)(a3 + 40) + v4 + 8 <= 0x20 ) /*0x12ce43*/
  {
    bzero(a1, 0x20u); /*0x12ce5b*/
    *(_DWORD *)a1 = *(_DWORD *)(*(_DWORD *)(a2 + 36) + 20); /*0x12ce66*/
    *((_DWORD *)a1 + 1) = *(_DWORD *)(*(_DWORD *)(a2 + 36) + 24); /*0x12ce6e*/
    v5 = v7; /*0x12ce71*/
    *((_WORD *)a1 + 4) = *v7; /*0x12ce77*/
    bcopy(v5 + 1, a1 + 10, *v5); /*0x12ce87*/
    v6 = **(_WORD **)(a3 + 40); /*0x12ce8f*/
    *((_WORD *)a1 + 10) = v6; /*0x12ce92*/
    bcopy((const void *)(*(_DWORD *)(a3 + 40) + 2), a1 + 22, v6); /*0x12cea7*/
    kfree((int)v7, *v7 + 2); /*0x12ceba*/
    return 0; /*0x12cebf*/
  }
  else
  {
    kfree((int)v7, v4 + 2); /*0x12ce4c*/
    return 71; /*0x12ce51*/
  }
}
