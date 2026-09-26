/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x104c54. */
int __cdecl execve(const char *__file, char *const *__argv, char *const *__envp)
{
  int v4; // eax
  _BYTE *v5; // ebx
  _BYTE *i; // ebx
  _BYTE *j; // esi
  int v8; // ebx
  _BYTE *v9; // esi
  _BYTE *v10; // edx
  int v11; // eax
  int machfile; // eax
  int v13; // eax
  _WORD *posix_proc; // ebx
  int v15; // edx
  int v16; // esi
  int v17; // ebx
  int v18; // edx
  int k; // ebx
  unsigned int v20; // edx
  int v22; // esi
  int v23; // ebx
  int n; // edx
  _BYTE *v25; // [esp+Ch] [ebp-114h]
  _BYTE *v26; // [esp+Ch] [ebp-114h]
  int v27; // [esp+10h] [ebp-110h]
  int v28; // [esp+18h] [ebp-108h]
  int v29; // [esp+18h] [ebp-108h]
  const char *v30; // [esp+1Ch] [ebp-104h]
  int v31; // [esp+28h] [ebp-F8h]
  int v32; // [esp+2Ch] [ebp-F4h]
  int v33; // [esp+30h] [ebp-F0h]
  int v34; // [esp+34h] [ebp-ECh]
  int v35; // [esp+38h] [ebp-E8h]
  int v36; // [esp+3Ch] [ebp-E4h]
  int v37; // [esp+3Ch] [ebp-E4h]
  int v38; // [esp+40h] [ebp-E0h]
  int v39; // [esp+44h] [ebp-DCh]
  _DWORD *v40; // [esp+48h] [ebp-D8h]
  int v41; // [esp+4Ch] [ebp-D4h]
  int v42; // [esp+4Ch] [ebp-D4h]
  int m; // [esp+4Ch] [ebp-D4h]
  vm_address_t address; // [esp+50h] [ebp-D0h] BYREF
  int v45; // [esp+54h] [ebp-CCh] BYREF
  unsigned int v46; // [esp+58h] [ebp-C8h] BYREF
  const char *v47[3]; // [esp+5Ch] [ebp-C4h] BYREF
  int v48; // [esp+68h] [ebp-B8h] BYREF
  _DWORD v49[8]; // [esp+6Ch] [ebp-B4h] BYREF
  _DWORD __b[4]; // [esp+8Ch] [ebp-94h] BYREF
  char v51; // [esp+9Ch] [ebp-84h]
  char v52[8]; // [esp+A0h] [ebp-80h] BYREF
  int v53; // [esp+A8h] [ebp-78h]
  int v54; // [esp+ACh] [ebp-74h]
  _BYTE v55[32]; // [esp+B4h] [ebp-6Ch] BYREF
  void *v56[2]; // [esp+D4h] [ebp-4Ch] BYREF
  unsigned int v57; // [esp+DCh] [ebp-44h]
  _BYTE v58[5]; // [esp+E0h] [ebp-40h] BYREF
  char v59; // [esp+E5h] [ebp-3Bh]
  __int16 v60; // [esp+E6h] [ebp-3Ah]
  __int16 v61; // [esp+E8h] [ebp-38h]

  v40 = *(_DWORD **)(dword_1E875C + 36); /*0x104c68*/
  v30 = *(const char **)(*(_DWORD *)(active_threads + 12) + 56); /*0x104c79*/
  v28 = pn_get(*v40, 0, v56); /*0x104c93*/
  if ( v28 ) /*0x104c9e*/
  {
    *(_BYTE *)(dword_1E875C + 104) = v28; /*0x104cab*/
    return v28; /*0x104cb4*/
  }
  v29 = lookuppn((int)v56, 1, nullptr, &v48); /*0x104ccd*/
  if ( !v29 && v48 )
  {
    v32 = 0; /*0x104cf0*/
    v35 = 0; /*0x104cfa*/
    v4 = *((_DWORD *)v30 + 7); /*0x104d0a*/
    v34 = *(__int16 *)(v4 + 2); /*0x104d11*/
    v33 = *(__int16 *)(v4 + 4); /*0x104d1b*/
    v29 = (*(int (__cdecl **)(int, _BYTE *, int))(*(_DWORD *)(v48 + 28) + 20))(v48, v58, v4); /*0x104d2f*/
    if ( v29 ) /*0x104d3a*/
      goto LABEL_132; /*0x104d3a*/
    if ( (*(_BYTE *)(*(_DWORD *)(v48 + 36) + 12) & 8) != 0 )
    {
      if ( (v59 & 0xC) != 0 )
      {
        v29 = pn_get(*v40, 0, v47); /*0x104dcd*/
        if ( v29 ) /*0x104dd8*/
          goto LABEL_132; /*0x104dd8*/
        uprintf("%s: Setuid execution not allowed\n", v47[0]);
        pn_free(v47); /*0x104df0*/
      }
    }
    else if ( (v59 & 0xC) != 0 )
    {
      if ( task_secure(*(_DWORD *)(active_threads + 12)) )
      {
        if ( (v59 & 8) != 0 ) /*0x104d75*/
          v34 = v60; /*0x104d7b*/
        if ( (v59 & 4) != 0 ) /*0x104d84*/
          v33 = v61; /*0x104d8a*/
      }
      else
      {
        uprintf("%s: privileges disabled because of outstanding IPC access to task\n", v30 + 8);
      }
    }
LABEL_18:
    v29 = check_exec_access(v48); /*0x104df8*/
    if ( v29 || (LOBYTE(v49[0]) = 0, (v29 = vn_rdwr(0, (int *)v48, (int)v49, 32, 0, 1, 1, &v46)) != 0) ) /*0x104e4b*/
    {
LABEL_132:
      pn_free(v56); /*0x10578f*/
      if ( v32 ) /*0x1057a2*/
        kmem_free_wakeup(kernel_pageable_map, v32, 40960); /*0x1057b7*/
      if ( v48 ) /*0x1057c7*/
        vn_rele(v48); /*0x1057ca*/
      goto LABEL_136; /*0x1057ca*/
    }
    if ( v46 > 0x18 && LOBYTE(v49[0]) != 35 ) /*0x104e61*/
      goto LABEL_89; /*0x104e61*/
    if ( v49[0] == -17958194 ) /*0x104e85*/
    {
      v31 = 0; /*0x104e87*/
    }
    else
    {
      if ( v49[0] != -889275714 && v49[0] != _byteswap_ulong(0xCAFEBABE) ) /*0x104ea9*/
      {
        if ( v49[0] == _byteswap_ulong(0xFEEDFACE) ) /*0x104ec5*/
        {
          v29 = 84; /*0x104ec7*/
          goto LABEL_132; /*0x104ed1*/
        }
        if ( LOWORD(v49[0]) != 8483 || v35 ) /*0x104eee*/
          goto LABEL_89; /*0x104eee*/
        v5 = (char *)v49 + 2; /*0x104ef4*/
        if ( (_DWORD *)((char *)v49 + 2) >= __b ) /*0x104f02*/
          goto LABEL_37; /*0x104f02*/
        while ( 1 ) /*0x104f08*/
        {
          if ( *v5 == 9 ) /*0x104f0c*/
          {
            *v5 = 32; /*0x104f18*/
          }
          else if ( *v5 == 10 ) /*0x104f10*/
          {
            *v5 = 0; /*0x104f12*/
LABEL_37:
            if ( !*v5 ) /*0x104f20*/
            {
              for ( i = (char *)v49 + 2; *i == 32; ++i ) /*0x104f36*/
                ; /*0x104f38*/
              for ( j = i; *i; ++i ) /*0x104f40*/
              {
                if ( *i == 32 ) /*0x104f4b*/
                  break; /*0x104f4b*/
              }
              v55[0] = 0; /*0x104f53*/
              if ( *i ) /*0x104f57*/
              {
                *i = 0; /*0x104f5c*/
                do /*0x104f64*/
                  ++i; /*0x104f60*/
                while ( *i == 32 ); /*0x104f64*/
                if ( *i ) /*0x104f66*/
                  bcopy(i, v55, 0x20u); /*0x104f72*/
              }
              v35 = 1; /*0x104f7a*/
              vn_rele(v48); /*0x104f8b*/
              v48 = 0; /*0x104f90*/
              v29 = pn_set(v56, j); /*0x104fa4*/
              if ( !v29 ) /*0x104faf*/
              {
                v29 = lookuppn((int)v56, 1, nullptr, &v48); /*0x104fc6*/
                if ( !v29 ) /*0x104fd1*/
                {
                  v29 = (*(int (__cdecl **)(int, _BYTE *, _DWORD))(*(_DWORD *)(v48 + 28) + 20))( /*0x104ff3*/
                          v48,
                          v58,
                          *(_DWORD *)(active_u + 28));
                  if ( !v29 ) /*0x104ffe*/
                    goto LABEL_18; /*0x104ffe*/
                }
              }
              goto LABEL_132; /*0x104ffe*/
            }
LABEL_89:
            v29 = 8; /*0x1052e2*/
            goto LABEL_132; /*0x1052ec*/
          }
          if ( ++v5 >= (_BYTE *)__b ) /*0x104f1e*/
            goto LABEL_37; /*0x104f1e*/
        }
      }
      v31 = 1; /*0x104eab*/
    }
    v39 = 0; /*0x10501c*/
    v38 = 0; /*0x105026*/
    v41 = 0; /*0x105030*/
    v32 = kmem_alloc_wait(kernel_pageable_map, 40960); /*0x10504b*/
    v8 = v32; /*0x105051*/
    v36 = 40960; /*0x105057*/
    if ( v40[1] ) /*0x10506a*/
    {
      while ( 1 ) /*0x105074*/
      {
        v9 = nullptr; /*0x105074*/
        v10 = nullptr; /*0x105076*/
        if ( !v35 ) /*0x10507f*/
          break; /*0x10507f*/
        if ( v39 ) /*0x105088*/
        {
          if ( v39 == 1 && v55[0] ) /*0x1050a9*/
          {
            v9 = v55; /*0x1050ab*/
            v10 = v55; /*0x1050ae*/
          }
          else
          {
            if ( v39 != 1 && (v39 != 2 || !v55[0]) ) /*0x1050d3*/
              break; /*0x1050d3*/
            v9 = (_BYTE *)*v40; /*0x1050db*/
          }
        }
        else
        {
          v9 = v56[0]; /*0x10508a*/
          v10 = v56[0]; /*0x10508d*/
          v40[1] += 4; /*0x105095*/
        }
LABEL_66:
        if ( !v9 ) /*0x105110*/
        {
          if ( v40[2] ) /*0x105118*/
          {
            v40[1] = 0; /*0x10511e*/
            v25 = v10; /*0x105129*/
            v9 = (_BYTE *)fuword(v40[2]); /*0x105134*/
            v10 = v25; /*0x105139*/
            if ( !v9 ) /*0x105141*/
              goto LABEL_82; /*0x105141*/
            v40[2] += 4; /*0x10514d*/
            ++v38; /*0x105151*/
          }
          if ( !v9 ) /*0x105159*/
            goto LABEL_82; /*0x105159*/
        }
        ++v39; /*0x10515f*/
        if ( v9 == (_BYTE *)-1 ) /*0x105168*/
        {
          v29 = 14; /*0x10500c*/
          goto LABEL_82; /*0x105016*/
        }
        if ( v41 > 40958 ) /*0x105178*/
        {
          v29 = 7; /*0x10517a*/
          goto LABEL_132; /*0x105184*/
        }
        while ( 1 ) /*0x10518e*/
        {
          if ( v10 ) /*0x10518e*/
          {
            v26 = v10; /*0x1051a0*/
            v29 = copystr(v10, v8, v36, &v45); /*0x1051ab*/
            v10 = &v26[v45]; /*0x1051b7*/
          }
          else
          {
            v29 = copyinstr(v9, v8, v36, &v45); /*0x1051df*/
            v9 += v45; /*0x1051e5*/
            v10 = nullptr; /*0x1051ee*/
          }
          v8 += v45; /*0x1051fa*/
          v41 += v45; /*0x1051fc*/
          v36 -= v45; /*0x105202*/
          if ( v29 != 2 ) /*0x10520f*/
            break; /*0x10520f*/
          if ( v41 > 40958 ) /*0x10521b*/
          {
            v29 = 7; /*0x105221*/
            break; /*0x105221*/
          }
        }
        if ( v29 ) /*0x105232*/
          goto LABEL_132; /*0x105232*/
      }
      if ( v40[1] ) /*0x1050e6*/
      {
        v9 = (_BYTE *)fuword(v40[1]); /*0x1050f9*/
        v40[1] += 4; /*0x105101*/
        v10 = nullptr; /*0x105108*/
      }
      goto LABEL_66; /*0x105108*/
    }
LABEL_82:
    v11 = v41 + 3; /*0x105240*/
    LOBYTE(v11) = (v41 + 3) & 0xFC; /*0x105249*/
    v42 = v11; /*0x10524b*/
    if ( v31 ) /*0x105258*/
    {
      machfile = fatfile_getarch(v48, v49, v52); /*0x105270*/
      if ( machfile ) /*0x10527a*/
        goto LABEL_84; /*0x10527a*/
      v29 = vn_rdwr(0, (int *)v48, (int)v49, 28, v53, 1, 1, &v46); /*0x1052aa*/
      if ( v29 ) /*0x1052b5*/
        goto LABEL_132; /*0x1052b5*/
      if ( v46 ) /*0x1052c2*/
      {
        v29 = 83; /*0x1052c4*/
        goto LABEL_132; /*0x1052ce*/
      }
      if ( v49[0] != -17958194 ) /*0x1052e0*/
        goto LABEL_89; /*0x1052e0*/
      machfile = load_machfile(v48, (int)v49, v53, v54, __b); /*0x105311*/
    }
    else
    {
      machfile = load_machfile(v48, (int)v49, 0, *(_DWORD *)(*(_DWORD *)v48 + 20), __b); /*0x105331*/
    }
    if ( !machfile ) /*0x10533b*/
    {
      if ( (*(_BYTE *)(*(_DWORD *)v30 + 40) & 0x10) != 0 ) /*0x105350*/
      {
        exception_from_kernel(6, nullptr, 0); /*0x10540a*/
      }
      else
      {
        posix_proc = (_WORD *)get_posix_proc(*(__int16 *)(*(_DWORD *)v30 + 48)); /*0x105360*/
        lock_write(active_u + 32); /*0x10536b*/
        v15 = *((_DWORD *)v30 + 7); /*0x105370*/
        if ( v34 != *(__int16 *)(v15 + 2) || v33 != *(__int16 *)(v15 + 4) ) /*0x10538c*/
          *((_DWORD *)v30 + 7) = crcopy(*((_DWORD *)v30 + 7)); /*0x10539a*/
        *(_WORD *)(*((_DWORD *)v30 + 7) + 2) = v34; /*0x1053b0*/
        *(_WORD *)(*(_DWORD *)v30 + 44) = v34; /*0x1053b6*/
        *(_WORD *)(*((_DWORD *)v30 + 7) + 4) = v33; /*0x1053c4*/
        lock_done(active_u + 32); /*0x1053d1*/
        posix_proc[4] = v33; /*0x1053dd*/
        posix_proc[2] = *(_WORD *)(*((_DWORD *)v30 + 7) + 6); /*0x1053ee*/
        posix_proc[3] = v34; /*0x1053f9*/
      }
      address = 0; /*0x105412*/
      if ( !vm_allocate(*(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12), &address, page_size, 0) ) /*0x105438*/
        vm_protect(*(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12), 0, page_size, 0, 0); /*0x10545d*/
      if ( v29 ) /*0x10546c*/
        goto LABEL_132; /*0x10546c*/
      vn_rele(v48); /*0x105479*/
      v48 = 0; /*0x10547e*/
      if ( (v51 & 1) == 0 || !create_unix_stack(*(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12), __b[2]) ) /*0x1054a7*/
      {
        if ( (v51 & 1) != 0 ) /*0x1054e3*/
        {
          v27 = *(_DWORD *)(*(_DWORD *)v30 + 132) - v42 - 4; /*0x1054f2*/
          v16 = v27 - 4 * v39 - 12; /*0x10550f*/
          *(_DWORD *)(*(_DWORD *)dword_1E875C + 68) = v16; /*0x105519*/
          suword(v16, v39 - v38); /*0x10552a*/
          v17 = v32; /*0x10552f*/
          v37 = 40960; /*0x105535*/
          do /*0x1055d2*/
          {
            v16 += 4; /*0x105550*/
            if ( v39 == v38 ) /*0x10555f*/
            {
              suword(v16, 0); /*0x105564*/
              v16 += 4; /*0x105569*/
            }
            if ( --v39 < 0 ) /*0x105575*/
              break; /*0x105575*/
            suword(v16, v27); /*0x10557f*/
            do /*0x1055c9*/
            {
              v29 = copyoutstr(v17, v27, v37, &v45); /*0x1055a3*/
              v27 += v45; /*0x1055b1*/
              v17 += v45; /*0x1055b7*/
              v37 -= v45; /*0x1055b9*/
            }
            while ( v29 == 2 ); /*0x1055c9*/
          }
          while ( v29 != 14 ); /*0x1055d2*/
          suword(v16, 0); /*0x1055db*/
        }
        if ( (v51 & 2) != 0 ) /*0x1055ea*/
        {
          v18 = *(_DWORD *)(*(_DWORD *)dword_1E875C + 68) - 4; /*0x1055f6*/
          *(_DWORD *)(*(_DWORD *)dword_1E875C + 68) = v18; /*0x1055f9*/
          suword(v18, __b[0]); /*0x105604*/
        }
        *(_DWORD *)(*(_DWORD *)dword_1E875C + 56) = __b[1]; /*0x105619*/
        for ( k = *(_DWORD *)v30; *(_DWORD *)(*(_DWORD *)v30 + 36); k = *(_DWORD *)v30 ) /*0x105624*/
        {
          v20 = *(_DWORD *)(k + 36); /*0x10562c*/
          if ( !_BitScanForward((unsigned int *)&v22, v20) ) /*0x10562f*/
            v22 = -1; /*0x105634*/
          *(_DWORD *)(k + 36) = __ROL4__(-2, v22) & v20; /*0x105644*/
          *(_DWORD *)&v30[4 * v22 + 52] = 0; /*0x10564d*/
        }
        *((_DWORD *)v30 + 83) = 0; /*0x105663*/
        *((_DWORD *)v30 + 82) = 0; /*0x10566d*/
        *((_DWORD *)v30 + 79) = 0; /*0x105677*/
        *((_DWORD *)v30 + 80) = 0; /*0x105681*/
        for ( m = *((_DWORD *)v30 + 86); m >= 0; --m ) /*0x105699*/
        {
          if ( (*(_BYTE *)(m + *((_DWORD *)v30 + 85)) & 1) != 0 ) /*0x1056b2*/
          {
            v23 = *(_DWORD *)(*((_DWORD *)v30 + 84) + 4 * m); /*0x1056ba*/
            vno_lockrelease(v23); /*0x1056be*/
            closef(v23); /*0x1056c4*/
            *(_DWORD *)(*((_DWORD *)v30 + 84) + 4 * m) = 0; /*0x1056d5*/
            *(_BYTE *)(m + *((_DWORD *)v30 + 85)) = 0; /*0x1056e2*/
          }
          *(_BYTE *)(m + *((_DWORD *)v30 + 85)) &= ~2u; /*0x1056fb*/
        }
        for ( n = *((_DWORD *)v30 + 86); n >= 0 && !*(_DWORD *)(*((_DWORD *)v30 + 84) + 4 * n); --n ) /*0x10571d*/
          *((_DWORD *)v30 + 86) = n - 1; /*0x10572d*/
        *(_BYTE *)(dword_1E875C + 105) = 1; /*0x105747*/
        *((_BYTE *)v30 + 580) &= ~1u; /*0x105751*/
        if ( v57 > 0x10 ) /*0x10575c*/
          v57 = 16; /*0x10575e*/
        bcopy(v56[0], (void *)(v30 + 8), v57 + 1); /*0x105778*/
        *(_DWORD *)(*(_DWORD *)v30 + 40) |= 0x80000000; /*0x105785*/
        goto LABEL_132; /*0x105785*/
      }
      v13 = sub_105A3C(5); /*0x1054b5*/
LABEL_105:
      v29 = v13; /*0x1054ba*/
      goto LABEL_132; /*0x1054c3*/
    }
LABEL_84:
    v13 = sub_105A3C(machfile); /*0x10527c*/
    goto LABEL_105; /*0x10527d*/
  }
  pn_free(v56); /*0x104ce5*/
LABEL_136:
  *(_BYTE *)(dword_1E875C + 104) = v29; /*0x1057cf*/
  return v29; /*0x1057e9*/
}
