/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17c17c. */
int __cdecl vm_object_special(__int16 a1, int (__cdecl *a2)(_DWORD, int, int), int a3, int a4, int a5)
{
  unsigned int v5; // ebx
  _DWORD *v6; // esi
  int v7; // edi
  signed int v8; // ebx
  _DWORD *v9; // esi
  int v10; // eax
  char v11; // cl
  int v13; // [esp+10h] [ebp-10h]
  signed int v14; // [esp+14h] [ebp-Ch]
  int v15; // [esp+18h] [ebp-8h]

  v14 = ((page_mask + a5) & (unsigned int)~page_mask) >> page_shift; /*0x17c1a8*/
  v15 = vm_object_allocate((page_mask + a5) & ~page_mask); /*0x17c1b1*/
  v5 = 48 * v14 + 16; /*0x17c1bd*/
  v6 = (_DWORD *)kalloc(v5); /*0x17c1c6*/
  bzero(v6, v5); /*0x17c1ca*/
  v7 = (int)v6; /*0x17c1cf*/
  *v6 = 1; /*0x17c1d1*/
  v6[1] = v15; /*0x17c1da*/
  v6[2] = v6; /*0x17c1dd*/
  v6[3] = v5; /*0x17c1e0*/
  v13 = (int)(v6 + 4); /*0x17c1e6*/
  v8 = 0; /*0x17c1e9*/
  if ( v14 > 0 ) /*0x17c1f1*/
  {
    v9 = v6 + 13; /*0x17c1f3*/
    do /*0x17c244*/
    {
      *((_WORD *)v9 - 4) = 1; /*0x17c1f8*/
      v10 = a2(a1, a4 + (v8 << page_shift), a3); /*0x17c218*/
      v11 = page_shift; /*0x17c21a*/
      *v9 = v10 << page_shift; /*0x17c222*/
      vm_page_insert(v13, v15, v8++ << v11); /*0x17c231*/
      v9 += 12; /*0x17c23a*/
      v13 += 48; /*0x17c23d*/
    }
    while ( v14 > v8 ); /*0x17c244*/
  }
  vm_object_setpager(v15, v7, 0); /*0x17c24f*/
  return v15; /*0x17c25a*/
}
