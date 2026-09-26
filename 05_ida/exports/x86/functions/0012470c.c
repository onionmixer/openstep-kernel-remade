/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12470c. */
int __cdecl sub_12470C(int a1, int a2, int a3, int a4, unsigned __int8 *a5, _DWORD *a6)
{
  int v6; // ebx
  int v7; // eax
  int v9; // [esp+Ch] [ebp-9Ch]
  int v10; // [esp+10h] [ebp-98h]
  int v11; // [esp+1Ch] [ebp-8Ch]
  int v12; // [esp+20h] [ebp-88h]
  int v13; // [esp+24h] [ebp-84h]
  int v14; // [esp+28h] [ebp-80h]
  int v15; // [esp+2Ch] [ebp-7Ch]
  int v16; // [esp+30h] [ebp-78h] BYREF
  _DWORD v17[2]; // [esp+34h] [ebp-74h] BYREF
  _DWORD v18[6]; // [esp+3Ch] [ebp-6Ch] BYREF
  int v19; // [esp+54h] [ebp-54h] BYREF
  int v20; // [esp+58h] [ebp-50h] BYREF
  _WORD v21[2]; // [esp+60h] [ebp-48h] BYREF
  int v22; // [esp+64h] [ebp-44h]
  _BYTE v23[56]; // [esp+70h] [ebp-38h] BYREF

  v10 = 0; /*0x124736*/
  v9 = 0; /*0x124740*/
  microtime(&v20); /*0x12474e*/
  v14 = v20 ^ a5[5]; /*0x12475d*/
  *(_DWORD *)(a3 + 32) = v14; /*0x124763*/
  v21[0] = 2; /*0x124766*/
  v21[1] = __ROR2__(67, 8); /*0x124778*/
  v22 = -1; /*0x12477c*/
  v13 = 1; /*0x124783*/
  v12 = 0; /*0x12478d*/
  v11 = 0; /*0x124797*/
  while ( 2 ) /*0x1247d0*/
  {
    if ( v12 || (v15 = in_bootp_bptombuf((char *)a3), (v6 = if_output_mbuf(a1, v15, (int)v21)) == 0) ) /*0x1247d0*/
    {
      qmemcpy(v23, (const void *)(dword_1E875C + 40), sizeof(v23)); /*0x1247e8*/
      if ( setjmp((int *)(dword_1E875C + 40)) ) /*0x1247f3*/
      {
        qmemcpy((void *)(dword_1E875C + 40), v23, 0x38u); /*0x124811*/
        untimeout((int)sub_124DE0, (int)&v19); /*0x12481c*/
        v6 = 4; /*0x124821*/
      }
      else
      {
        v19 = a2; /*0x124833*/
        timeout((int)sub_124DE0); /*0x124846*/
        while ( 1 ) /*0x1248a2*/
        {
          while ( 1 ) /*0x124853*/
          {
            v17[0] = a4; /*0x124853*/
            v17[1] = 300; /*0x124856*/
            v18[0] = v17; /*0x124860*/
            v18[1] = 1; /*0x124863*/
            v18[3] = 1; /*0x12486a*/
            v18[2] = 0; /*0x124871*/
            v18[5] = 300; /*0x124878*/
            v6 = soreceive(a2, nullptr, (int)v18, 0, nullptr); /*0x124892*/
            if ( v6 != 35 || a2 != v19 ) /*0x1248a2*/
              break; /*0x1248a2*/
            sbwait(v19 + 36); /*0x1248a8*/
          }
          if ( v6 && v6 != 35 ) /*0x1248bb*/
          {
            qmemcpy((void *)(dword_1E875C + 40), v23, 0x38u); /*0x1248cf*/
            untimeout((int)sub_124DE0, (int)&v19); /*0x1248da*/
            goto LABEL_33; /*0x1248e2*/
          }
          if ( !v19 ) /*0x1248ec*/
            break; /*0x1248ec*/
          if ( *(_DWORD *)(a4 + 4) == v14 && *(_BYTE *)a4 == 2 && !bcmp((const void *)(a4 + 28), a5, 6u) ) /*0x12499e*/
          {
            if ( *(_BYTE *)(a3 + 270) || !*(_BYTE *)(a4 + 242) ) /*0x1249c0*/
            {
LABEL_30:
              qmemcpy((void *)(dword_1E875C + 40), v23, 0x38u); /*0x124a06*/
              untimeout((int)sub_124DE0, (int)&v19); /*0x124a23*/
              if ( v10 ) /*0x124a32*/
                printf("Network responded!\n"); /*0x124a39*/
              v6 = 0; /*0x124a41*/
              goto LABEL_33; /*0x124a41*/
            }
            if ( v9 ) /*0x1249cd*/
            {
              if ( v16 != 1 ) /*0x124a00*/
                goto LABEL_30; /*0x124a00*/
            }
            else
            {
              v9 = 1; /*0x1249cf*/
              v16 = 1; /*0x1249d9*/
              timeout((int)sub_124DFC); /*0x1249f4*/
            }
          }
        }
        qmemcpy((void *)(dword_1E875C + 40), v23, 0x38u); /*0x124904*/
        v7 = v12 + 1; /*0x12490c*/
        v12 = v7; /*0x12490d*/
        ++v11; /*0x124913*/
        if ( v13 == v7 ) /*0x12491f*/
        {
          if ( v7 <= 63 ) /*0x124924*/
            v13 = 2 * v7; /*0x124928*/
          v12 = 0; /*0x12492e*/
        }
        if ( v11 != 20 ) /*0x12493f*/
          continue; /*0x12493f*/
        if ( *a6 || (v6 = sub_124A60(a6)) == 0 ) /*0x12495a*/
        {
          printf( /*0x124965*/
            " \n"
            "No response from network configuration server.\n"
            "Type Control-C to start up computer without a network\n"
            "connection.\n");
          v10 = 1; /*0x12496a*/
          continue; /*0x124977*/
        }
      }
    }
    break;
  }
LABEL_33:
  untimeout((int)sub_124DFC, (int)&v16); /*0x124a43*/
  return v6; /*0x124a59*/
}
