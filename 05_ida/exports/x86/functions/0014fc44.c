/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14fc44. */
int __cdecl ipc_right_rename(unsigned int a1, unsigned int a2, int *a3, unsigned int a4, int *a5)
{
  int v5; // ebx
  int *v7; // eax
  volatile __int32 *v8; // edx
  unsigned int v9; // [esp+Ch] [ebp-10h]
  unsigned int v10; // [esp+Ch] [ebp-10h]
  int v11; // [esp+10h] [ebp-Ch]
  int v12; // [esp+14h] [ebp-8h]
  int v13; // [esp+18h] [ebp-4h]

  v13 = *a3; /*0x14fc52*/
  v12 = a3[2]; /*0x14fc58*/
  v11 = a3[1]; /*0x14fc5e*/
  if ( v12 ) /*0x14fc63*/
  {
    do /*0x14fc7e*/
    {
      while ( *(_DWORD *)v11 ) /*0x14fc6c*/
        ; /*0x14fc6e*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v11, 1) == 1 ); /*0x14fc7e*/
    if ( *(int *)(v11 + 8) < 0 ) /*0x14fc84*/
    {
      *(_DWORD *)(*(_DWORD *)(v11 + 44) + 8 * v12 + 4) = a4; /*0x14fd90*/
      _InterlockedExchange((volatile __int32 *)v11, 0); /*0x14fd95*/
      a3[2] = 0; /*0x14fd97*/
    }
    else
    {
      _InterlockedExchange((volatile __int32 *)v11, 0); /*0x14fc8c*/
      v5 = *a3; /*0x14fc8e*/
      v9 = *a3; /*0x14fc90*/
      if ( (*a3 & 0x10000) != 0 ) /*0x14fc99*/
      {
        if ( (v5 & 0x200000) != 0 ) /*0x14fca1*/
        {
          v9 = v5 & 0xFFDFFFFF; /*0x14fca9*/
          ipc_marequest_cancel(a1, a2); /*0x14fcb4*/
        }
        ipc_hash_delete(a1, v11, a2, (int)a3); /*0x14fcc6*/
      }
      ipc_object_release(v11); /*0x14fccf*/
      if ( (v9 & 0x400000) != 0 ) /*0x14fce0*/
      {
        a3[2] = 0; /*0x14fce2*/
        a3[1] = 0; /*0x14fce9*/
        ipc_entry_dealloc((_DWORD *)a1, a2, a3); /*0x14fcf9*/
      }
      else
      {
        v10 = v9 & 0xFFE0FFFF | 0x100000; /*0x14fd15*/
        if ( a3[2] ) /*0x14fd18*/
        {
          a3[2] = 0; /*0x14fd1e*/
          ++v10; /*0x14fd25*/
        }
        *a3 = v10; /*0x14fd2b*/
        a3[1] = 0; /*0x14fd2d*/
      }
      if ( (v13 & 0x400000) != 0 ) /*0x14fd46*/
      {
        ipc_entry_dealloc((_DWORD *)a1, a4, a5); /*0x14fd54*/
        _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14fd5b*/
        return 15; /*0x14fd63*/
      }
      v13 = *a3; /*0x14fd6a*/
      v12 = 0; /*0x14fd6d*/
      v11 = 0; /*0x14fd74*/
    }
  }
  if ( (v13 & 0x200000) != 0 ) /*0x14fda7*/
    ipc_marequest_rename(a1, a2, a4); /*0x14fdb5*/
  *a5 |= v13 & 0x7FFFFF; /*0x14fdc8*/
  a5[2] = v12; /*0x14fdcd*/
  a5[1] = v11; /*0x14fdd3*/
  v7 = (int *)(v13 & 0x1F0000); /*0x14fdd9*/
  if ( (v13 & 0x1F0000) == 0x30000 ) /*0x14fde3*/
  {
LABEL_32:
    v8 = (volatile __int32 *)v11; /*0x14fe54*/
    do /*0x14fe6a*/
    {
      while ( *(_DWORD *)v11 ) /*0x14fe58*/
        ; /*0x14fe5a*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v11, 1) == 1 ); /*0x14fe6a*/
    *(_DWORD *)(v11 + 16) = a4; /*0x14fe6f*/
LABEL_40:
    _InterlockedExchange(v8, 0); /*0x14fe92*/
    goto LABEL_42; /*0x14fe96*/
  }
  if ( (v13 & 0x1F0000u) > 0x30000 ) /*0x14fde5*/
  {
    if ( v7 == (int *)0x80000 ) /*0x14fe01*/
    {
      v8 = (volatile __int32 *)v11; /*0x14fe74*/
      do /*0x14fe8a*/
      {
        while ( *(_DWORD *)v11 ) /*0x14fe78*/
          ; /*0x14fe7a*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v11, 1) == 1 ); /*0x14fe8a*/
      *(_DWORD *)(v11 + 12) = a4; /*0x14fe8f*/
      goto LABEL_40; /*0x14fe8f*/
    }
    if ( (unsigned int)v7 > 0x80000 ) /*0x14fe03*/
    {
      if ( v7 == &dword_100000 ) /*0x14fe1d*/
        goto LABEL_42; /*0x14fe1d*/
    }
    else if ( v7 == (int *)0x40000 ) /*0x14fe0a*/
    {
      goto LABEL_42; /*0x14fe0a*/
    }
LABEL_41:
    panic(aIpcRightRename); /*0x14fe98*/
  }
  if ( v7 != (int *)0x10000 ) /*0x14fdec*/
  {
    if ( v7 != (int *)0x20000 ) /*0x14fdf3*/
      goto LABEL_41; /*0x14fdf3*/
    goto LABEL_32; /*0x14fdf3*/
  }
  ipc_hash_delete(a1, v11, a2, (int)a3); /*0x14fe35*/
  ipc_hash_insert(a1, v11, a4, (int)a5); /*0x14fe4a*/
LABEL_42:
  a3[1] = 0; /*0x14fea5*/
  ipc_entry_dealloc((_DWORD *)a1, a2, a3); /*0x14feb5*/
  _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14febc*/
  return 0; /*0x14fec4*/
}
