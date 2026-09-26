/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x191848. */
int setconf()
{
  char *v0; // ebx
  int i; // ebx
  int v2; // edx
  char v3; // dl
  const char *v4; // edx
  __int16 v5; // ax
  __int16 v6; // ax
  __int16 v8; // [esp+Ch] [ebp-94h]
  id v9; // [esp+10h] [ebp-90h] BYREF
  char __s1[12]; // [esp+14h] [ebp-8Ch] BYREF
  char v11[128]; // [esp+20h] [ebp-80h] BYREF

  v8 = 0; /*0x191854*/
  if ( MEMORY[0x110A4] != -1482184793 ) /*0x191868*/
    panic(aInvalidBootStr); /*0x19186f*/
  strcpy(rootfs, "4.3"); /*0x19187d*/
  if ( (boothowto & 1) != 0 ) /*0x19188a*/
    goto LABEL_6; /*0x19188a*/
  if ( !rootdevice ) /*0x191893*/
  {
    boottype = MEMORY[0x110AC]; /*0x191aa2*/
    v6 = ((int)MEMORY[0x110AC] >> 13) & 0x7F8 | MEMORY[0x110AD] | (MEMORY[0x110AC] << 8); /*0x191ac7*/
    goto LABEL_42; /*0x191ac7*/
  }
  while ( 1 ) /*0x1918a0*/
  {
    if ( (boothowto & 1) != 0 ) /*0x1918a0*/
    {
LABEL_6:
      printf("root device? "); /*0x1918a7*/
      v0 = v11; /*0x1918ac*/
      gets(v11); /*0x1918b1*/
    }
    else
    {
      if ( !strcmp(aCdrom, &rootdevice) ) /*0x1918d2*/
      {
        v9 = nullptr; /*0x1918d6*/
        for ( i = 0; i <= 15; ++i ) /*0x1918e0*/
        {
          sprintf(__s1, "sd%d", i); /*0x1918ef*/
          if ( IOGetObjectForDeviceName(__s1, (int)&v9) ) /*0x1918fc*/
            break; /*0x191906*/
          if ( (unsigned __int8)objc_msgSend(v9, sel_inquiryDeviceType) == 5 ) /*0x191920*/
          {
            v0 = __s1; /*0x191948*/
            goto LABEL_17; /*0x19194a*/
          }
        }
        if ( sub_191C68() ) /*0x191928*/
          printf("No CD-ROM drive found\n"); /*0x191936*/
        else
          printf("No SCSI controller or CD-ROM drive found\n"); /*0x191941*/
        goto LABEL_31; /*0x191936*/
      }
      v0 = &rootdevice; /*0x19194c*/
LABEL_17:
      printf("root on %s\n", v0); /*0x191957*/
    }
    dword_1E7740 = (int)&genericconf; /*0x19195f*/
    if ( !genericconf ) /*0x191970*/
      goto LABEL_31; /*0x191970*/
    while ( 1 ) /*0x191974*/
    {
      v2 = dword_1E7740; /*0x191974*/
      if ( **(_BYTE **)dword_1E7740 == *v0 && *(_BYTE *)(*(_DWORD *)dword_1E7740 + 1) == v0[1] ) /*0x191988*/
        break; /*0x191988*/
      dword_1E7740 += 8; /*0x19198d*/
      if ( !*(_DWORD *)(v2 + 8) ) /*0x191993*/
        goto LABEL_31; /*0x191997*/
    }
    if ( *(_WORD *)(dword_1E7740 + 4) == 0xFFFF ) /*0x1919a1*/
      goto LABEL_39; /*0x1919a1*/
    if ( (unsigned __int8)(v0[2] - 48) > 7u ) /*0x1919ae*/
    {
      printf("bad/missing unit number\n"); /*0x1919e5*/
      goto LABEL_31; /*0x1919e5*/
    }
    v3 = v0[3]; /*0x1919b0*/
    if ( (unsigned __int8)(v3 - 97) <= 7u ) /*0x1919b9*/
      break; /*0x1919b9*/
    if ( !v3 ) /*0x1919bd*/
      goto LABEL_38; /*0x1919bd*/
    printf("bad partition number\n"); /*0x1919c4*/
LABEL_31:
    dword_1E7740 = (int)&genericconf; /*0x1919ed*/
    if ( genericconf ) /*0x1919fe*/
    {
      do /*0x191a45*/
      {
        if ( (_UNKNOWN **)dword_1E7740 == &genericconf ) /*0x191a0d*/
        {
          v4 = aUse; /*0x191a24*/
        }
        else
        {
          v4 = aOr; /*0x191a0f*/
          if ( *(_DWORD *)(dword_1E7740 + 8) ) /*0x191a14*/
            v4 = asc_1E2724; /*0x191a1a*/
        }
        printf("%s%s%%d", v4, *(const char **)dword_1E7740); /*0x191a2f*/
        dword_1E7740 += 8; /*0x191a3f*/
      }
      while ( *(_DWORD *)dword_1E7740 ); /*0x191a45*/
    }
    printf("\n"); /*0x191a50*/
    LOBYTE(boothowto) = boothowto | 1; /*0x191a55*/
  }
  v8 = v3 - 97; /*0x1919ce*/
LABEL_38:
  v5 = *(_WORD *)(dword_1E7740 + 4); /*0x191a64*/
  if ( v5 == -1 ) /*0x191a72*/
  {
LABEL_39:
    strcpy(rootfs, "nfs"); /*0x191a74*/
    return printf("rootdev %x, howto %x\n", rootdev, boothowto); /*0x191a80*/
  }
  LOBYTE(v5) = 0; /*0x191a84*/
  v6 = (v8 + 8 * (v0[2] - 48)) | v5; /*0x191a90*/
  *(_WORD *)(dword_1E7740 + 4) = v6; /*0x191a93*/
LABEL_42:
  rootdev = v6; /*0x191aca*/
  return printf("rootdev %x, howto %x\n", rootdev, boothowto); /*0x191aef*/
}
