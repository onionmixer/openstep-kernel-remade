/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12696c. */
int __cdecl ip_dooptions(_DWORD *a1, int a2)
{
  unsigned __int8 *v2; // edi
  char v3; // al
  unsigned int v4; // ebx
  unsigned int v5; // ebx
  unsigned __int8 *v6; // ebx
  int v7; // eax
  int v8; // edx
  char v9; // bl
  unsigned int v10; // ebx
  int v11; // edx
  unsigned int v12; // edx
  char v13; // al
  int v14; // eax
  int v15; // eax
  void *v17; // [esp+Ch] [ebp-1Ch]
  unsigned __int8 *v18; // [esp+Ch] [ebp-1Ch]
  unsigned int v19; // [esp+10h] [ebp-18h]
  unsigned int v20; // [esp+18h] [ebp-10h]
  int i; // [esp+1Ch] [ebp-Ch]
  int v22; // [esp+20h] [ebp-8h]
  unsigned __int32 v23; // [esp+24h] [ebp-4h] BYREF

  v20 = 12; /*0x126975*/
  v2 = (unsigned __int8 *)(a1 + 5); /*0x12697f*/
  for ( i = 4 * (*(_BYTE *)a1 & 0xF) - 20; i > 0; v2 += v22 ) /*0x126996*/
  {
    v17 = (void *)*v2; /*0x12699f*/
    if ( !*v2 ) /*0x1269a4*/
      return 0; /*0x1269a4*/
    if ( *v2 == 1 ) /*0x1269ad*/
    {
      v22 = 1; /*0x1269af*/
    }
    else
    {
      v22 = v2[1]; /*0x1269bc*/
      if ( !v2[1] || v2[1] > i ) /*0x1269c8*/
      {
        v3 = (_BYTE)a1 - 1; /*0x1269cd*/
LABEL_49:
        v9 = (_BYTE)v2 - v3; /*0x126c72*/
        goto LABEL_50; /*0x126c74*/
      }
    }
    if ( v17 == (void *)68 ) /*0x1269d8*/
    {
      v9 = (_BYTE)v2 - (_BYTE)a1; /*0x126b46*/
      if ( v2[1] <= 4u ) /*0x126b51*/
        goto LABEL_50; /*0x126b51*/
      v12 = v2[2]; /*0x126b57*/
      v19 = v2[1]; /*0x126b60*/
      if ( v12 <= v19 - 4 ) /*0x126b68*/
      {
        v18 = &v2[v12 - 1]; /*0x126b98*/
        v14 = v2[3] & 0xF; /*0x126b9e*/
        if ( v14 == 1 ) /*0x126ba4*/
        {
          if ( v19 < v12 + 8 ) /*0x126bc6*/
            goto LABEL_50; /*0x126bc6*/
          v15 = ifptoia(a2); /*0x126bd0*/
          bcopy((const void *)(v15 + 4), v18, 4u); /*0x126be1*/
          v2[2] += 4; /*0x126be6*/
          goto LABEL_44; /*0x126bed*/
        }
        if ( (v2[3] & 0xFu) <= 1 ) /*0x126ba6*/
        {
          if ( (v2[3] & 0xF) != 0 ) /*0x126baa*/
            goto LABEL_50; /*0x126baa*/
          goto LABEL_44; /*0x126baa*/
        }
        if ( v14 != 2 || v19 < v12 + 8 ) /*0x126bf6*/
          goto LABEL_50; /*0x126bf6*/
        bcopy(v18, &dword_1DBD94, 4u); /*0x126c03*/
        if ( ifa_ifwithaddr(ipaddr) ) /*0x126c0d*/
        {
          v2[2] += 4; /*0x126c19*/
LABEL_44:
          v23 = iptime(); /*0x126c1d*/
          bcopy(&v23, &v2[v2[2] - 1], 4u); /*0x126c37*/
          v2[2] += 4; /*0x126c3c*/
        }
      }
      else
      {
        v13 = (v2[3] >> 4) + 1; /*0x126b77*/
        v2[3] = (16 * v13) | v2[3] & 0xF; /*0x126b82*/
        if ( (v13 & 0xF) == 0 ) /*0x126b87*/
          goto LABEL_50; /*0x126b87*/
      }
    }
    else if ( *v2 > 0x44u ) /*0x1269de*/
    {
      if ( v17 == (void *)131 || v17 == (void *)137 ) /*0x126a00*/
      {
        v4 = v2[2]; /*0x126a06*/
        if ( v4 <= 3 ) /*0x126a0d*/
          goto LABEL_48; /*0x126a0d*/
        dword_1DBD94 = a1[4]; /*0x126a19*/
        if ( ifa_ifwithaddr(ipaddr) ) /*0x126a24*/
        {
          v5 = v4 - 1; /*0x126a44*/
          if ( v5 <= v22 - 4 ) /*0x126a4d*/
          {
            v6 = &v2[v5]; /*0x126a6b*/
            bcopy(v6, &dword_1DBD94, 4u); /*0x126a6e*/
            if ( v17 == (void *)137 && (v7 = in_netof(dword_1DBD94), !in_iaonnetof(v7)) /*0x126aab*/
              || (v8 = ip_rtaddr(dword_1DBD94)) == 0 )
            {
LABEL_23:
              v20 = 3; /*0x126aad*/
              v9 = 5; /*0x126ab4*/
LABEL_50:
              icmp_error(a1, v20, v9, a2, nullptr); /*0x126c76*/
              return 1; /*0x126c8a*/
            }
            a1[4] = dword_1DBD94; /*0x126ac9*/
            bcopy((const void *)(v8 + 4), v6, 4u); /*0x126ad3*/
            v2[2] += 4; /*0x126ad8*/
          }
          else
          {
            save_rte(v2, a1[3]); /*0x126a57*/
          }
        }
        else if ( v17 == (void *)137 ) /*0x126a39*/
        {
          goto LABEL_23; /*0x126a39*/
        }
      }
    }
    else if ( v17 == (void *)7 ) /*0x1269e4*/
    {
      if ( v2[2] <= 3u ) /*0x126aeb*/
      {
LABEL_48:
        v3 = (_BYTE)a1 - 2; /*0x126c6c*/
        goto LABEL_49; /*0x126c6f*/
      }
      v10 = v2[2] - 1; /*0x126af1*/
      if ( v10 <= v22 - 4 ) /*0x126afa*/
      {
        bcopy(a1 + 4, &dword_1DBD94, 4u); /*0x126b0e*/
        v11 = ip_rtaddr(dword_1DBD94); /*0x126b1f*/
        if ( !v11 ) /*0x126b26*/
        {
          v20 = 3; /*0x126c5c*/
          v9 = 1; /*0x126c63*/
          goto LABEL_50; /*0x126c68*/
        }
        bcopy((const void *)(v11 + 4), &v2[v10], 4u); /*0x126b36*/
        v2[2] += 4; /*0x126b3b*/
      }
    }
    i -= v22; /*0x126c43*/
  }
  return 0; /*0x126c92*/
}
