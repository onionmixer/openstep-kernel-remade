/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12bf80. */
void igmp_fasttimo()
{
  int v0; // ebx
  int v1; // edx
  int v2; // eax
  int v3; // eax
  int v4; // [esp+4h] [ebp-8h]
  int v5; // [esp+8h] [ebp-4h]

  if ( dword_1DBF44 ) /*0x12bf8e*/
  {
    v0 = splnet(); /*0x12bf99*/
    dword_1DBF44 = 0; /*0x12bf9b*/
    v4 = in_ifaddr; /*0x12bfab*/
    v5 = 0; /*0x12bfae*/
    v1 = 0; /*0x12bfb5*/
    while ( v4 ) /*0x12bfbe*/
    {
      v1 = *(_DWORD *)(v4 + 68); /*0x12bfc3*/
      v4 = *(_DWORD *)(v4 + 64); /*0x12bfc9*/
      if ( v1 ) /*0x12bfce*/
        goto LABEL_11; /*0x12bfce*/
    }
    while ( 1 ) /*0x12c007*/
    {
      while ( 1 ) /*0x12c030*/
      {
LABEL_15:
        if ( !v1 ) /*0x12c032*/
        {
          splx(v0); /*0x12c035*/
          return; /*0x12c035*/
        }
        v2 = *(_DWORD *)(v1 + 16); /*0x12bfd8*/
        if ( v2 ) /*0x12bfdd*/
        {
          *(_DWORD *)(v1 + 16) = v2 - 1; /*0x12bfe2*/
          if ( v2 == 1 ) /*0x12bfe8*/
            igmp_sendreport(v1); /*0x12bfeb*/
          else
            dword_1DBF44 = 1; /*0x12bff8*/
        }
        v1 = v5; /*0x12c002*/
        if ( !v5 ) /*0x12c007*/
          break; /*0x12c007*/
LABEL_11:
        v5 = *(_DWORD *)(v1 + 20); /*0x12c009*/
      }
      if ( v4 ) /*0x12c018*/
      {
        while ( 1 ) /*0x12c01f*/
        {
          v1 = *(_DWORD *)(v4 + 68); /*0x12c01f*/
          v3 = *(_DWORD *)(v4 + 64); /*0x12c022*/
          v4 = v3; /*0x12c025*/
          if ( v1 ) /*0x12c02a*/
            goto LABEL_11; /*0x12c02a*/
          if ( !v3 ) /*0x12c02e*/
            goto LABEL_15; /*0x12c02e*/
        }
      }
    }
  }
}
