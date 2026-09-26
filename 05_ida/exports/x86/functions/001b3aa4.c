/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b3aa4. */
id __cdecl -[KeyMap _parseKeyMapping:length:into:](
        KeyMap *self,
        SEL a2,
        const char *a3,
        int a4,
        $5F1FB785E9540639F1FC986CD3AD7963 *a5)
{
  int v5; // eax
  int v6; // eax
  int v7; // esi
  int v8; // ecx
  int v9; // eax
  int v10; // eax
  char v11; // cl
  int v12; // eax
  char v13; // dl
  int v14; // eax
  int v15; // esi
  int v16; // eax
  int v17; // ecx
  int var2; // edx
  int v19; // ecx
  int v20; // edx
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // esi
  int v25; // ecx
  int v26; // eax
  int v27; // eax
  int i; // esi
  int v29; // esi
  int v30; // ecx
  int v31; // eax
  unsigned __int16 v32; // ax
  int j; // esi
  int v35; // eax
  int v36; // [esp+Ch] [ebp-20h]
  int v37; // [esp+Ch] [ebp-20h]
  int v38; // [esp+10h] [ebp-1Ch]
  int v39; // [esp+10h] [ebp-1Ch]
  int v40; // [esp+18h] [ebp-14h]
  int v41; // [esp+1Ch] [ebp-10h]
  int v42; // [esp+1Ch] [ebp-10h]
  char *v43; // [esp+20h] [ebp-Ch]
  const char *v44; // [esp+24h] [ebp-8h]
  int v45; // [esp+28h] [ebp-4h]

  v40 = -1; /*0x1b3ab0*/
  bzero(a5, 0x4F0u); /*0x1b3ac0*/
  a5->var2 = -1; /*0x1b3ac5*/
  a5->var4 = -1; /*0x1b3acf*/
  a5->var6 = -1; /*0x1b3ad9*/
  v44 = &a3[a4]; /*0x1b3ae8*/
  v43 = (char *)a3; /*0x1b3aee*/
  a5->var10 = (char *)a3; /*0x1b3afb*/
  a5->var11 = a4; /*0x1b3b01*/
  if ( &a3[a4] > a3 ) /*0x1b3b0d*/
  {
    v5 = *(unsigned __int16 *)a3; /*0x1b3b1a*/
    v43 = (char *)(a3 + 2); /*0x1b3b1d*/
  }
  else
  {
    v5 = 0; /*0x1b3b0f*/
  }
  v45 = v5; /*0x1b3b2a*/
  a5->var0 = v5; /*0x1b3b30*/
  if ( v44 > v43 ) /*0x1b3b39*/
  {
    if ( v5 ) /*0x1b3b48*/
    {
      v6 = *(unsigned __int16 *)v43; /*0x1b3b4a*/
      v43 += 2; /*0x1b3b4d*/
    }
    else
    {
      v6 = (unsigned __int8)*v43++; /*0x1b3b54*/
    }
    v38 = v6; /*0x1b3b5a*/
  }
  else
  {
    v38 = 0; /*0x1b3b3b*/
  }
  v7 = 0; /*0x1b3b5d*/
  if ( v38 <= 0 ) /*0x1b3b62*/
  {
LABEL_37:
    if ( v44 > v43 ) /*0x1b3c54*/
    {
      if ( v45 ) /*0x1b3c60*/
      {
        v14 = *(unsigned __int16 *)v43; /*0x1b3c62*/
        v43 += 2; /*0x1b3c65*/
      }
      else
      {
        v14 = (unsigned __int8)*v43++; /*0x1b3c6c*/
      }
    }
    else
    {
      v14 = 0; /*0x1b3c56*/
    }
    a5->var4 = v14; /*0x1b3c75*/
    v42 = v14; /*0x1b3c7b*/
    v15 = 0; /*0x1b3c7e*/
    while ( 1 ) /*0x1b3c80*/
    {
      if ( v42 <= v15 ) /*0x1b3c83*/
      {
        a5->var5[v15] = nullptr; /*0x1b3da3*/
      }
      else
      {
        a5->var5[v15] = v43; /*0x1b3c8f*/
        if ( v44 > v43 ) /*0x1b3c9c*/
        {
          if ( v45 ) /*0x1b3ca8*/
          {
            v16 = *(unsigned __int16 *)v43; /*0x1b3caa*/
            v43 += 2; /*0x1b3cad*/
          }
          else
          {
            v16 = (unsigned __int8)*v43++; /*0x1b3cb4*/
          }
        }
        else
        {
          v16 = 0; /*0x1b3c9e*/
        }
        if ( v45 ) /*0x1b3cbe*/
        {
          if ( v16 != 0xFFFF ) /*0x1b3cc5*/
            goto LABEL_53; /*0x1b3cc5*/
        }
        else if ( v16 != 255 ) /*0x1b3cd1*/
        {
LABEL_53:
          a5->var1[v15] |= 0x20u; /*0x1b3cd7*/
          v17 = 0; /*0x1b3cdf*/
          v37 = 1; /*0x1b3ce1*/
          var2 = a5->var2; /*0x1b3ce8*/
          if ( var2 >= 0 ) /*0x1b3cf0*/
          {
            do /*0x1b3d05*/
            {
              if ( (v16 & 1) != 0 ) /*0x1b3cf6*/
                v37 *= 2; /*0x1b3cfd*/
              ++v17; /*0x1b3d00*/
              v16 >>= 1; /*0x1b3d01*/
            }
            while ( v17 <= var2 ); /*0x1b3d05*/
          }
          v19 = 0; /*0x1b3d07*/
          if ( v37 <= 0 ) /*0x1b3d0c*/
            goto LABEL_79; /*0x1b3d0c*/
          while ( 2 ) /*0x1b3d26*/
          {
            if ( v44 > v43 ) /*0x1b3d26*/
            {
              if ( v45 ) /*0x1b3d30*/
              {
                v21 = *(unsigned __int16 *)v43; /*0x1b3d32*/
                v43 += 2; /*0x1b3d35*/
              }
              else
              {
                v21 = (unsigned __int8)*v43++; /*0x1b3d3c*/
              }
              v20 = v21; /*0x1b3d42*/
            }
            else
            {
              v20 = 0; /*0x1b3d28*/
            }
            if ( v44 > v43 ) /*0x1b3d4a*/
            {
              if ( v45 ) /*0x1b3d54*/
              {
                v22 = *(unsigned __int16 *)v43; /*0x1b3d56*/
                v43 += 2; /*0x1b3d59*/
              }
              else
              {
                v22 = (unsigned __int8)*v43++; /*0x1b3d60*/
              }
            }
            else
            {
              v22 = 0; /*0x1b3d4c*/
            }
            if ( v45 ) /*0x1b3d6a*/
            {
              if ( v20 != 0xFFFF ) /*0x1b3d72*/
                goto LABEL_75; /*0x1b3d72*/
            }
            else if ( v20 != 255 ) /*0x1b3d7e*/
            {
              goto LABEL_75; /*0x1b3d7e*/
            }
            if ( v40 < v22 ) /*0x1b3d83*/
              v40 = v22; /*0x1b3d85*/
LABEL_75:
            if ( v37 <= ++v19 ) /*0x1b3d8c*/
              goto LABEL_79; /*0x1b3d8c*/
            continue; /*0x1b3d8c*/
          }
        }
        a5->var5[v15] = nullptr; /*0x1b3d93*/
      }
LABEL_79:
      if ( ++v15 > 127 ) /*0x1b3db2*/
      {
        if ( v44 > v43 ) /*0x1b3dbe*/
        {
          if ( v45 ) /*0x1b3dc8*/
          {
            v23 = *(unsigned __int16 *)v43; /*0x1b3dca*/
            v43 += 2; /*0x1b3dcd*/
          }
          else
          {
            v23 = (unsigned __int8)*v43++; /*0x1b3dd4*/
          }
        }
        else
        {
          v23 = 0; /*0x1b3dc0*/
        }
        a5->var6 = v23; /*0x1b3ddd*/
        if ( v40 < v23 ) /*0x1b3de6*/
        {
          v24 = 0; /*0x1b3dec*/
          if ( v23 > 0 ) /*0x1b3df0*/
          {
            do /*0x1b3e76*/
            {
              a5->var7[v24] = v43; /*0x1b3dfe*/
              v25 = 0; /*0x1b3e05*/
              if ( v44 > v43 ) /*0x1b3e0d*/
              {
                if ( v45 ) /*0x1b3e18*/
                {
                  v26 = *(unsigned __int16 *)v43; /*0x1b3e1a*/
                  v43 += 2; /*0x1b3e1d*/
                }
                else
                {
                  v26 = (unsigned __int8)*v43++; /*0x1b3e24*/
                }
              }
              else
              {
                v26 = 0; /*0x1b3e0f*/
              }
              if ( v26 > 0 ) /*0x1b3e2c*/
              {
                do /*0x1b3e6a*/
                {
                  if ( v43 < v44 ) /*0x1b3e3e*/
                  {
                    if ( v45 ) /*0x1b3e42*/
                      v43 += 2; /*0x1b3e44*/
                    else
                      ++v43; /*0x1b3e4c*/
                    if ( v43 < v44 ) /*0x1b3e55*/
                    {
                      if ( v45 ) /*0x1b3e59*/
                        v43 += 2; /*0x1b3e5b*/
                      else
                        ++v43; /*0x1b3e64*/
                    }
                  }
                  ++v25; /*0x1b3e67*/
                }
                while ( v25 < v26 ); /*0x1b3e6a*/
              }
              ++v24; /*0x1b3e6c*/
            }
            while ( a5->var6 > v24 ); /*0x1b3e76*/
          }
          if ( v44 > v43 ) /*0x1b3e7e*/
          {
            if ( v45 ) /*0x1b3e90*/
            {
              v27 = *(unsigned __int16 *)v43; /*0x1b3e92*/
              v43 += 2; /*0x1b3e95*/
            }
            else
            {
              v27 = (unsigned __int8)*v43++; /*0x1b3e9c*/
            }
            v39 = v27; /*0x1b3ea2*/
          }
          else
          {
            v39 = 0; /*0x1b3e80*/
          }
          if ( v39 <= 9 && v39 ) /*0x1b3eb3*/
          {
            for ( i = 8; i >= 0; --i ) /*0x1b3eb5*/
              a5->var9[i] = -1; /*0x1b3ebf*/
            v29 = 0; /*0x1b3ecc*/
            while ( 1 ) /*0x1b3eda*/
            {
              if ( v44 > v43 ) /*0x1b3eda*/
              {
                if ( v45 ) /*0x1b3ee4*/
                {
                  v31 = *(unsigned __int16 *)v43; /*0x1b3ee6*/
                  v43 += 2; /*0x1b3ee9*/
                }
                else
                {
                  v31 = (unsigned __int8)*v43++; /*0x1b3ef0*/
                }
                v30 = v31; /*0x1b3ef6*/
              }
              else
              {
                v30 = 0; /*0x1b3edc*/
              }
              if ( v44 > v43 ) /*0x1b3efe*/
              {
                if ( v45 ) /*0x1b3f08*/
                {
                  v32 = *(_WORD *)v43; /*0x1b3f0a*/
                  v43 += 2; /*0x1b3f0d*/
                }
                else
                {
                  v32 = (unsigned __int8)*v43++; /*0x1b3f14*/
                }
              }
              else
              {
                v32 = 0; /*0x1b3f00*/
              }
              if ( v30 > 8 ) /*0x1b3f1d*/
                break; /*0x1b3f1d*/
              a5->var9[v30] = v32; /*0x1b3f22*/
              if ( v39 <= ++v29 ) /*0x1b3f2e*/
              {
                for ( j = 0; j <= 6; ++j ) /*0x1b3f38*/
                {
                  if ( a5->var9[j] != 0xFFFF ) /*0x1b3f4b*/
                  {
                    v35 = a5->var9[j]; /*0x1b3f4d*/
                    a5->var1[v35] |= 0x60u; /*0x1b3f52*/
                  }
                }
                return self; /*0x1b3f5d*/
              }
            }
          }
        }
        return nullptr; /*0x1b3f1d*/
      }
    }
  }
  while ( 1 ) /*0x1b3b6e*/
  {
    if ( v44 > v43 ) /*0x1b3b6e*/
    {
      if ( v45 ) /*0x1b3b78*/
      {
        v9 = *(unsigned __int16 *)v43; /*0x1b3b7a*/
        v43 += 2; /*0x1b3b7d*/
      }
      else
      {
        v9 = (unsigned __int8)*v43++; /*0x1b3b84*/
      }
      v8 = v9; /*0x1b3b8a*/
    }
    else
    {
      v8 = 0; /*0x1b3b70*/
    }
    if ( v8 > 15 ) /*0x1b3b8f*/
      return nullptr; /*0x1b3f63*/
    if ( a5->var2 < v8 ) /*0x1b3b9e*/
      a5->var2 = v8; /*0x1b3ba0*/
    a5->var3[v8] = v43; /*0x1b3bac*/
    v36 = 0; /*0x1b3bb3*/
    if ( v44 > v43 ) /*0x1b3bc0*/
    {
      if ( v45 ) /*0x1b3bd0*/
      {
        v10 = *(unsigned __int16 *)v43; /*0x1b3bd2*/
        v43 += 2; /*0x1b3bd5*/
      }
      else
      {
        v10 = (unsigned __int8)*v43++; /*0x1b3bdc*/
      }
      v41 = v10; /*0x1b3be2*/
    }
    else
    {
      v41 = 0; /*0x1b3bc2*/
    }
    if ( v41 > 0 ) /*0x1b3beb*/
    {
      v11 = v8 & 0xF | 0x10; /*0x1b3bf3*/
      do /*0x1b3bfe*/
      {
        if ( v44 > v43 ) /*0x1b3bfe*/
        {
          if ( v45 ) /*0x1b3c08*/
          {
            v12 = *(unsigned __int16 *)v43; /*0x1b3c0a*/
            v43 += 2; /*0x1b3c0d*/
          }
          else
          {
            v12 = (unsigned __int8)*v43++; /*0x1b3c14*/
          }
        }
        else
        {
          v12 = 0; /*0x1b3c00*/
        }
        if ( v12 > 127 ) /*0x1b3c1d*/
          return nullptr; /*0x1b3c2d*/
        v13 = a5->var1[v12]; /*0x1b3c26*/
        if ( (v13 & 0x10) != 0 ) /*0x1b3c2d*/
          return nullptr; /*0x1b3c2d*/
        a5->var1[v12] = v11 | v13; /*0x1b3c35*/
      }
      while ( ++v36 < v41 ); /*0x1b3bfe*/
    }
    if ( v38 <= ++v7 ) /*0x1b3c48*/
      goto LABEL_37; /*0x1b3c48*/
  }
}
