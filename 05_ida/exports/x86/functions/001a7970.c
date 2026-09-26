/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a7970. */
id sub_1A7970()
{
  int v0; // ebx
  int v1; // edi
  int *v2; // ecx
  int *v3; // esi
  int *v4; // eax
  int *v5; // eax
  void *v6; // esi
  int *v7; // eax
  int v8; // eax
  int v9; // eax
  int *v10; // ecx
  int *v11; // esi
  int *v12; // eax
  int *v13; // eax
  id v15; // [esp+Ch] [ebp-8h]
  id v16; // [esp+10h] [ebp-4h]

  v0 = 0; /*0x1a7979*/
  objc_msgSend(dword_1E86E8, sel_lock); /*0x1a7989*/
  while ( (int *)dword_1E86E0 != &dword_1E86E0 )
  {
    v1 = dword_1E86E0; /*0x1a79a4*/
    v2 = *(int **)(dword_1E86E0 + 16); /*0x1a79aa*/
    v3 = *(int **)(dword_1E86E0 + 20); /*0x1a79ad*/
    v4 = &dword_1E86E0; /*0x1a79b0*/
    if ( v2 != &dword_1E86E0 ) /*0x1a79bb*/
      v4 = v2 + 4; /*0x1a79bd*/
    v4[1] = (int)v3; /*0x1a79c0*/
    v5 = &dword_1E86E0; /*0x1a79c3*/
    if ( v3 != &dword_1E86E0 ) /*0x1a79ce*/
      v5 = v3 + 4; /*0x1a79d0*/
    *v5 = (int)v2; /*0x1a79d3*/
    objc_msgSend(dword_1E86E8, sel_unlock); /*0x1a79e3*/
    v6 = *(void **)(v1 + 4); /*0x1a79e8*/
    if ( !*(_DWORD *)v1 ) /*0x1a79ee*/
      goto LABEL_14; /*0x1a79ee*/
    v7 = (int *)dword_1E86D8; /*0x1a79f3*/
    if ( (int *)dword_1E86D8 == &dword_1E86D8 ) /*0x1a79fd*/
    {
LABEL_10:
      v0 = 0; /*0x1a7a0e*/
    }
    else
    {
      while ( (void *)*v7 != v6 ) /*0x1a7a02*/
      {
        v7 = (int *)v7[6]; /*0x1a7a04*/
        if ( v7 == &dword_1E86D8 ) /*0x1a7a0c*/
          goto LABEL_10; /*0x1a7a0c*/
      }
      v0 = (int)v7; /*0x1a7a3c*/
    }
    if ( v0 )
    {
LABEL_14:
      switch ( *(_DWORD *)v1 ) /*0x1a7a4b*/
      {
        case 0: /*0x1a7a4b*/
          v15 = objc_msgSend(v6, sel_updateReadyState); /*0x1a7a82*/
          objc_msgSend(v6, sel_setLastReadyState_, v15); /*0x1a7a85*/
          if ( v15 /*0x1a7aac*/
            || (sub_1A7C70(v6, *(_WORD *)(v1 + 12), *(_WORD *)(v1 + 14)),
                (unsigned __int8)objc_msgSend(v6, sel_isRemovable)) )
          {
            v8 = IOMalloc(32); /*0x1a7abe*/
            v0 = v8; /*0x1a7ac3*/
            *(_DWORD *)v8 = v6; /*0x1a7ac5*/
            *(_WORD *)(v8 + 4) = *(_WORD *)(v1 + 12); /*0x1a7acb*/
            *(_WORD *)(v8 + 6) = *(_WORD *)(v1 + 14); /*0x1a7ad3*/
            *(_DWORD *)(v8 + 8) = 0; /*0x1a7ad7*/
            *(_BYTE *)(v8 + 12) = 0; /*0x1a7ade*/
            *(_BYTE *)(v8 + 13) = 0; /*0x1a7ae2*/
            *(_DWORD *)(v8 + 20) = *(_DWORD *)(v1 + 8); /*0x1a7ae9*/
            if ( (int *)dword_1E86D8 == &dword_1E86D8 ) /*0x1a7af9*/
            {
              dword_1E86D8 = v8; /*0x1a7bec*/
              dword_1E86DC = v8; /*0x1a7bf2*/
              *(_DWORD *)(v8 + 24) = &dword_1E86D8; /*0x1a7bf8*/
              *(_DWORD *)(v8 + 28) = &dword_1E86D8; /*0x1a7bff*/
            }
            else
            {
              v9 = dword_1E86DC; /*0x1a7aff*/
              *(_DWORD *)(v0 + 28) = dword_1E86DC; /*0x1a7b04*/
              *(_DWORD *)(v0 + 24) = &dword_1E86D8; /*0x1a7b07*/
              dword_1E86DC = v0; /*0x1a7b0e*/
              *(_DWORD *)(v9 + 24) = v0; /*0x1a7b14*/
            }
          }
          break; /*0x1a7b17*/
        case 1: /*0x1a7a4b*/
          v10 = *(int **)(v0 + 24); /*0x1a7b1c*/
          v11 = *(int **)(v0 + 28); /*0x1a7b1f*/
          v12 = &dword_1E86D8; /*0x1a7b22*/
          if ( v10 != &dword_1E86D8 ) /*0x1a7b2d*/
            v12 = v10 + 6; /*0x1a7b2f*/
          v12[1] = (int)v11; /*0x1a7b32*/
          v13 = &dword_1E86D8; /*0x1a7b35*/
          if ( v11 != &dword_1E86D8 ) /*0x1a7b40*/
            v13 = v11 + 6; /*0x1a7b42*/
          *v13 = (int)v10; /*0x1a7b45*/
          IOFree(v0, 32); /*0x1a7b4a*/
          break; /*0x1a7b4f*/
        case 2: /*0x1a7a4b*/
          v16 = objc_msgSend(v6, sel_unit); /*0x1a7b61*/
          if ( !*(_BYTE *)(v0 + 13) && objc_msgSend(v6, sel_lastReadyState) ) /*0x1a7b79*/
          {
            vol_panel_disk_num(sub_1A7D6C, 0, *(_DWORD *)(v1 + 8), v16, v6, 0, v0 + 16); /*0x1a7b9f*/
            *(_BYTE *)(v0 + 13) = 1; /*0x1a7ba4*/
          }
          break; /*0x1a7bab*/
        case 3: /*0x1a7a4b*/
          objc_msgSend(v6, sel_setLastReadyState_, 3); /*0x1a7bba*/
          *(_DWORD *)(v0 + 8) = 1; /*0x1a7bbf*/
          *(_BYTE *)(v0 + 12) = 0; /*0x1a7bc6*/
          *(_DWORD *)(v0 + 20) = *(_DWORD *)(v1 + 8); /*0x1a7bcd*/
          break; /*0x1a7bd3*/
        case 4: /*0x1a7a4b*/
          objc_msgSend(v6, sel_setLastReadyState_, 1); /*0x1a7be2*/
          break; /*0x1a7bea*/
        case 5: /*0x1a7a4b*/
          if ( *(_BYTE *)(v0 + 13) ) /*0x1a7c08*/
          {
            *(_BYTE *)(v0 + 13) = 0; /*0x1a7c0e*/
            objc_msgSend(v6, sel_abortRequest); /*0x1a7c1a*/
          }
          break; /*0x1a7c1a*/
        default:
          break;
      }
    }
    else
    {
      objc_msgSend(v6, sel_name); /*0x1a7a1f*/
      IOLog("volCheck: disk %s not registered, cmd = %d\n");
    }
    IOFree(v1, 24); /*0x1a7c22*/
    objc_msgSend(dword_1E86E8, sel_lock); /*0x1a7c38*/
  }
  return objc_msgSend(dword_1E86E8, sel_unlock); /*0x1a7c66*/
}
