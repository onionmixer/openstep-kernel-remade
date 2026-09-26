/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14fb2c. */
int __cdecl ipc_right_copyout(int a1, unsigned int a2, int *a3, unsigned int a4, int a5, int a6)
{
  int v6; // ebx
  int v8; // [esp+Ch] [ebp-4h]

  v6 = *a3; /*0x14fb41*/
  if ( a4 != 17 ) /*0x14fb46*/
  {
    if ( a4 > 0x11 ) /*0x14fb48*/
    {
      if ( a4 != 18 ) /*0x14fb5b*/
        goto LABEL_22; /*0x14fb5b*/
      _InterlockedExchange((volatile __int32 *)a6, 0); /*0x14fb63*/
      *a3 = v6 | 0x40001; /*0x14fb6b*/
    }
    else
    {
      if ( a4 != 16 ) /*0x14fb4d*/
LABEL_22:
        panic(aIpcRightCopyou); /*0x14fc2c*/
      v8 = *(_DWORD *)(a6 + 12); /*0x14fbe3*/
      *(_DWORD *)(a6 + 16) = a2; /*0x14fbe6*/
      *(_DWORD *)(a6 + 12) = a1; /*0x14fbec*/
      if ( (v6 & 0x10000) != 0 ) /*0x14fbf5*/
      {
        --*(_DWORD *)(a6 + 4); /*0x14fbf7*/
        _InterlockedExchange((volatile __int32 *)a6, 0); /*0x14fbfc*/
        ipc_hash_delete(a1, a6, a2, (int)a3); /*0x14fc02*/
      }
      else
      {
        _InterlockedExchange((volatile __int32 *)a6, 0); /*0x14fc0e*/
      }
      *a3 = v6 | 0x20000; /*0x14fc16*/
      if ( v8 ) /*0x14fc1c*/
        ipc_object_release(v8); /*0x14fc22*/
    }
    return 0; /*0x14fc27*/
  }
  if ( (v6 & 0x10000) == 0 ) /*0x14fb7a*/
  {
    if ( (v6 & 0x20000) == 0 ) /*0x14fbb6*/
    {
      _InterlockedExchange((volatile __int32 *)a6, 0); /*0x14fbc6*/
      ipc_hash_insert(a1, a6, a2, (int)a3); /*0x14fbcf*/
      goto LABEL_16; /*0x14fbcf*/
    }
LABEL_14:
    --*(_DWORD *)(a6 + 4); /*0x14fbb8*/
    _InterlockedExchange((volatile __int32 *)a6, 0); /*0x14fbbd*/
LABEL_16:
    *a3 = (v6 | 0x10000) + 1; /*0x14fbd4*/
    return 0; /*0x14fbde*/
  }
  if ( (_WORD)v6 != 0xFFFE ) /*0x14fb81*/
  {
    --*(_DWORD *)(a6 + 28); /*0x14fba8*/
    goto LABEL_14; /*0x14fbab*/
  }
  if ( !a5 ) /*0x14fb87*/
  {
    _InterlockedExchange((volatile __int32 *)a6, 0); /*0x14fb9a*/
    return 19; /*0x14fba1*/
  }
  --*(_DWORD *)(a6 + 28); /*0x14fb89*/
  --*(_DWORD *)(a6 + 4); /*0x14fb8c*/
  _InterlockedExchange((volatile __int32 *)a6, 0); /*0x14fb91*/
  return 0; /*0x14fc3b*/
}
