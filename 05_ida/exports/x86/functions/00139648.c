/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x139648. */
int __cdecl specvp(int a1, unsigned __int16 a2, int a3)
{
  int v3; // ebx
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // eax
  int v8; // edx
  int (__cdecl *v9)(_DWORD); // eax
  int v10; // eax
  int v11; // edx
  int v12; // edx
  _BYTE v14[32]; // [esp+Ch] [ebp-40h] BYREF
  int v15; // [esp+2Ch] [ebp-20h]
  int v16; // [esp+30h] [ebp-1Ch]
  int v17; // [esp+34h] [ebp-18h]
  int v18; // [esp+38h] [ebp-14h]
  int v19; // [esp+3Ch] [ebp-10h]
  int v20; // [esp+40h] [ebp-Ch]

  v3 = sub_139A30(a2, a1, a3); /*0x139666*/
  if ( !v3 ) /*0x13966d*/
  {
    if ( a1 && *(_DWORD *)(a1 + 40) == 8 ) /*0x13967b*/
    {
      v3 = fifosp(a1); /*0x139683*/
    }
    else
    {
      v3 = kalloc(104); /*0x139693*/
      bzero((void *)v3, 0x68u); /*0x139698*/
      *(_DWORD *)(v3 + 32) = &spec_vnodeops; /*0x13969d*/
      if ( a1 /*0x1396c0*/
        && !(*(int (__cdecl **)(int, _BYTE *, _DWORD))(*(_DWORD *)(a1 + 28) + 20))(a1, v14, *(_DWORD *)(active_u + 28)) )
      {
        v4 = v16; /*0x1396cc*/
        *(_DWORD *)(v3 + 76) = v15; /*0x1396cf*/
        *(_DWORD *)(v3 + 80) = v4; /*0x1396d2*/
        v5 = v18; /*0x1396d8*/
        *(_DWORD *)(v3 + 84) = v17; /*0x1396db*/
        *(_DWORD *)(v3 + 88) = v5; /*0x1396de*/
        v6 = v20; /*0x1396e4*/
        *(_DWORD *)(v3 + 92) = v19; /*0x1396e7*/
        *(_DWORD *)(v3 + 96) = v6; /*0x1396ea*/
      }
    }
    *(_DWORD *)(v3 + 56) = a1; /*0x1396ed*/
    *(_WORD *)(v3 + 66) = a2; /*0x1396f0*/
    *(_WORD *)(v3 + 48) = a2; /*0x1396f4*/
    *(_WORD *)(v3 + 10) = 1; /*0x1396f8*/
    *(_DWORD *)(v3 + 52) = v3; /*0x1396fe*/
    if ( a1 ) /*0x139703*/
    {
      ++*(_WORD *)(a1 + 6); /*0x139705*/
      *(_DWORD *)(v3 + 44) = *(_DWORD *)(a1 + 40); /*0x13970c*/
      *(_DWORD *)(v3 + 40) = *(_DWORD *)(a1 + 36); /*0x139712*/
      if ( *(_DWORD *)(a1 + 40) == 3 ) /*0x139719*/
      {
        v7 = specvp(0, a2, 3); /*0x139723*/
        *(_DWORD *)(v3 + 60) = v7; /*0x13972b*/
        *(_DWORD *)(v3 + 72) = *(_DWORD *)(*(_DWORD *)(v7 + 48) + 72); /*0x139734*/
      }
    }
    else
    {
      *(_DWORD *)(v3 + 44) = 3; /*0x13973c*/
      *(_DWORD *)(v3 + 40) = 0; /*0x139743*/
      *(_DWORD *)(v3 + 60) = v3 + 4; /*0x13974d*/
    }
    sub_139860(v3); /*0x139751*/
  }
  v8 = HIBYTE(a2); /*0x13975f*/
  if ( nblkdev <= v8 /*0x139781*/
    || (v9 = (int (__cdecl *)(_DWORD))*(&off_1E2D04 + 6 * v8)) == nullptr
    || (v10 = v9((__int16)a2), v10 == -1) )
  {
    *(_DWORD *)(v3 + 72) = 0; /*0x13979c*/
  }
  else
  {
    *(_DWORD *)(v3 + 72) = v10; /*0x139783*/
    v11 = *(_DWORD *)(v3 + 60); /*0x139786*/
    if ( v11 ) /*0x13978b*/
    {
      v12 = *(_DWORD *)(v11 + 48); /*0x13978d*/
      if ( !*(_DWORD *)(v12 + 72) ) /*0x139790*/
        *(_DWORD *)(v12 + 72) = v10; /*0x139796*/
    }
  }
  return v3 + 4; /*0x1397a9*/
}
