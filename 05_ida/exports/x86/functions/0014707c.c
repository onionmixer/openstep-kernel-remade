/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14707c. */
void __cdecl ipc_kmsg_clean_body(unsigned __int8 *a1, unsigned int a2)
{
  int v3; // eax
  unsigned int v4; // edi
  _DWORD *v5; // esi
  _BOOL4 v6; // edx
  _DWORD *i; // eax
  unsigned int j; // ebx
  int v9; // eax
  vm_size_t v10; // eax
  vm_address_t v11; // eax
  vm_size_t size; // [esp+Ch] [ebp-18h]
  _BOOL4 v13; // [esp+14h] [ebp-10h]
  _DWORD *v14; // [esp+18h] [ebp-Ch]
  _BOOL4 v15; // [esp+1Ch] [ebp-8h]
  int v16; // [esp+20h] [ebp-4h]

  while ( a2 > (unsigned int)a1 ) /*0x14708b*/
  {
    v15 = (a1[3] & 0x10) != 0; /*0x14709e*/
    if ( (a1[3] & 0x20) != 0 ) /*0x1470a4*/
    {
      v16 = *((unsigned __int16 *)a1 + 2); /*0x1470aa*/
      v3 = *((unsigned __int16 *)a1 + 3); /*0x1470ad*/
      v4 = *((_DWORD *)a1 + 2); /*0x1470b1*/
      v5 = a1 + 12; /*0x1470b4*/
    }
    else
    {
      v16 = *a1; /*0x1470bf*/
      v3 = a1[1]; /*0x1470c2*/
      v4 = *((_WORD *)a1 + 1) & 0xFFF; /*0x1470ca*/
      v5 = a1 + 4; /*0x1470d0*/
    }
    size = (v4 * v3 + 7) >> 3; /*0x1470dc*/
    v6 = (unsigned int)(v16 - 16) <= 5; /*0x1470eb*/
    if ( (unsigned int)(v16 - 16) <= 5 ) /*0x1470f0*/
    {
      if ( v15 ) /*0x1470f6*/
      {
        v14 = v5; /*0x1470f8*/
        for ( i = &v5[v4]; a2 < (unsigned int)i; --v4 ) /*0x147101*/
          --i; /*0x147104*/
      }
      else
      {
        v14 = (_DWORD *)*v5; /*0x147112*/
      }
      for ( j = 0; j < v4; ++j ) /*0x147119*/
      {
        v9 = v14[j]; /*0x14711f*/
        if ( v9 && v9 != -1 ) /*0x147129*/
        {
          v13 = v6; /*0x147130*/
          ipc_object_destroy(v9, v16); /*0x147133*/
          v6 = v13; /*0x14713b*/
        }
      }
    }
    if ( v15 ) /*0x147147*/
    {
      v10 = size + 3; /*0x14714c*/
      LOBYTE(v10) = (size + 3) & 0xFC; /*0x14714f*/
      a1 = (unsigned __int8 *)v5 + v10; /*0x147151*/
    }
    else
    {
      v11 = *v5; /*0x147158*/
      if ( size ) /*0x14715e*/
      {
        if ( v6 ) /*0x147162*/
          kfree(v11, size); /*0x147169*/
        else
          vm_deallocate(ipc_soft_map, v11, size); /*0x147180*/
      }
      a1 = (unsigned __int8 *)(v5 + 1); /*0x147188*/
    }
  }
}
