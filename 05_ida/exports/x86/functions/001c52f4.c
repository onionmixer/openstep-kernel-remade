/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c52f4. */
void __cdecl -[IOSVGADisplay _VGADisplayCursor:shmem:](
        IOSVGADisplay *self,
        SEL a2,
        $514E7C50D28E54AB164B6500F83867A3 *a3,
        $E63760587FADDAA675F803BB3FBE6402 *a4)
{
  int v4; // esi
  int v5; // edi
  __int16 v6; // dx
  int v7; // edx
  int v8; // esi
  int v9; // edx
  int v10; // edx
  int v11; // edi
  unsigned int i; // esi
  int v13; // [esp+Ch] [ebp-48h]
  int v14; // [esp+Ch] [ebp-48h]
  int v15; // [esp+14h] [ebp-40h]
  unsigned int v16; // [esp+18h] [ebp-3Ch]
  int v17; // [esp+1Ch] [ebp-38h]
  int v18; // [esp+20h] [ebp-34h]
  unsigned int v19; // [esp+24h] [ebp-30h]
  int v20; // [esp+28h] [ebp-2Ch]
  int v21; // [esp+2Ch] [ebp-28h]
  int v22; // [esp+34h] [ebp-20h]
  _BOOL4 v23; // [esp+38h] [ebp-1Ch]
  _BOOL4 v24; // [esp+3Ch] [ebp-18h]
  char *v25; // [esp+40h] [ebp-14h]
  char *v26; // [esp+40h] [ebp-14h]
  _DWORD *v27; // [esp+44h] [ebp-10h]
  char *v28; // [esp+48h] [ebp-Ch]
  char *v29; // [esp+48h] [ebp-Ch]
  int v30; // [esp+4Ch] [ebp-8h]
  int v31; // [esp+50h] [ebp-4h]

  v30 = *((_DWORD *)a4 + 12); /*0x1c5303*/
  v31 = *((_DWORD *)a4 + 13); /*0x1c5309*/
  -[IOSVGADisplay savePlaneAndSegmentSettings](self, sel_savePlaneAndSegmentSettings); /*0x1c5316*/
  v4 = *((_DWORD *)a4 + 8); /*0x1c531e*/
  v5 = *((_DWORD *)a4 + 9); /*0x1c5321*/
  if ( (__int16)v31 > (__int16)v5 ) /*0x1c532b*/
    LOWORD(v5) = v31; /*0x1c532d*/
  if ( SHIWORD(v5) > SHIWORD(v31) ) /*0x1c5341*/
    v5 = (v31 >> 16 << 16) | (unsigned __int16)v5; /*0x1c534d*/
  v6 = *((_WORD *)a4 + 16) - v30; /*0x1c535a*/
  LOBYTE(v6) = v6 & 0xF0; /*0x1c535d*/
  LOWORD(v4) = v30 + v6; /*0x1c5364*/
  HIWORD(v7) = HIWORD(v4); /*0x1c5367*/
  LOWORD(v7) = v30 + v6 + 32; /*0x1c5369*/
  v8 = (v7 << 16) | (unsigned __int16)v4; /*0x1c5378*/
  *((_DWORD *)a4 + 3) = v8; /*0x1c537b*/
  *((_DWORD *)a4 + 4) = v5; /*0x1c537e*/
  v22 = 2 * (*((_WORD *)a4 + 16) & 0xF); /*0x1c538a*/
  v9 = *(_DWORD *)a4 << 6; /*0x1c539c*/
  v28 = (char *)a4 + v9 + 72; /*0x1c53a3*/
  v25 = (char *)a4 + v9 + 328; /*0x1c53ad*/
  v27 = (_DWORD *)((char *)a4 + 584); /*0x1c53b5*/
  v10 = 4 * ((__int16)v5 - *((__int16 *)a4 + 18)); /*0x1c53c9*/
  v29 = &v28[v10]; /*0x1c53cc*/
  v26 = &v25[v10]; /*0x1c53cf*/
  v24 = (__int16)v30 <= (__int16)v8; /*0x1c53df*/
  v23 = SHIWORD(v8) <= SHIWORD(v30); /*0x1c53fd*/
  v21 = ((__int16)v8 - (__int16)v30) >> 4; /*0x1c5408*/
  v20 = a3->var0 >> 4; /*0x1c5415*/
  v19 = 0x10000 / (a3->var0 >> 3); /*0x1c5427*/
  v16 = (__int16)v5 - (__int16)v31; /*0x1c5433*/
  v15 = (v5 >> 16) - (__int16)v31; /*0x1c543d*/
  v11 = 2 * v21 + 2 * v20 * (v16 % v19) + 655360; /*0x1c5458*/
  v18 = v16 / v19; /*0x1c545f*/
  v17 = v19 * (v16 / v19 + 1); /*0x1c5469*/
  -[IOSVGADisplay setWriteSegment:](self, sel_setWriteSegment_, (unsigned __int8)(v16 / v19)); /*0x1c547b*/
  -[IOSVGADisplay setReadSegment:](self, sel_setReadSegment_, (unsigned __int8)(v16 / v19)); /*0x1c548b*/
  for ( i = v16; v15 > (int)i; ++i ) /*0x1c5499*/
  {
    if ( v17 == i ) /*0x1c54a3*/
    {
      v11 = 2 * v20 * (i % v19) + 655360 + 2 * v21; /*0x1c54ba*/
      ++v18; /*0x1c54bd*/
      v17 = i + v19; /*0x1c54c5*/
      -[IOSVGADisplay setWriteSegment:](self, sel_setWriteSegment_, (unsigned __int8)v18); /*0x1c54d8*/
      -[IOSVGADisplay setReadSegment:](self, sel_setReadSegment_, (unsigned __int8)v18); /*0x1c54e9*/
    }
    if ( v24 ) /*0x1c54f5*/
    {
      -[IOSVGADisplay _readBpp4planar:toBpp2packed32:](self, sel__readBpp4planar_toBpp2packed32_, v11, &dword_1E872C); /*0x1c5508*/
      v13 = dword_1E872C; /*0x1c5513*/
      *v27++ = dword_1E872C; /*0x1c5519*/
      dword_1E872C = (*(_DWORD *)v29 << v22) | v13 & ~(*(_DWORD *)v26 << v22); /*0x1c5539*/
      -[IOSVGADisplay _writeBpp2packed32:toBpp4planar:](self, sel__writeBpp2packed32_toBpp4planar_, &dword_1E872C, v11); /*0x1c5550*/
    }
    if ( v23 ) /*0x1c555c*/
    {
      if ( v22 ) /*0x1c5562*/
      {
        -[IOSVGADisplay _readBpp4planar:toBpp2packed32:]( /*0x1c5580*/
          self,
          sel__readBpp4planar_toBpp2packed32_,
          v11 + 2,
          &dword_1E8730);
        v14 = dword_1E8730; /*0x1c558b*/
        *v27++ = dword_1E8730; /*0x1c5591*/
        dword_1E8730 = (*(_DWORD *)v29 >> (32 - v22)) | v14 & ~(*(_DWORD *)v26 >> (32 - v22)); /*0x1c55b1*/
        -[IOSVGADisplay _writeBpp2packed32:toBpp4planar:]( /*0x1c55c8*/
          self,
          sel__writeBpp2packed32_toBpp4planar_,
          &dword_1E8730,
          v11 + 2);
      }
      else
      {
        ++v27; /*0x1c5564*/
      }
    }
    v11 += 2 * v20; /*0x1c55d3*/
    v29 += 4; /*0x1c55d6*/
    v26 += 4; /*0x1c55da*/
  }
  -[IOSVGADisplay restorePlaneAndSegmentSettings](self, sel_restorePlaneAndSegmentSettings); /*0x1c55f2*/
}
