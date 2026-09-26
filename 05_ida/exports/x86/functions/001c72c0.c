/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c72c0. */
id __cdecl -[IOVPCodeDisplay jumpTo:withInitialSRegs:](IOVPCodeDisplay *self, SEL a2, int a3, unsigned int *a4)
{
  const char *v4; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  unsigned int v10; // esi
  const char *v12; // eax
  unsigned int *vpCode; // edx
  unsigned int v14; // ebx
  int v15; // eax
  unsigned int videoRamAddress; // edx
  int v17; // ecx
  IOVPCodeDisplay *v18; // ecx
  int v19; // eax
  const char *v20; // eax
  unsigned __int8 v21; // al
  unsigned __int16 v22; // ax
  const char *v23; // eax
  int v24; // [esp-4h] [ebp-64h]
  int v25; // [esp-4h] [ebp-64h]
  unsigned int v26; // [esp-4h] [ebp-64h]
  char v27; // [esp+14h] [ebp-4Ch]
  char v28; // [esp+18h] [ebp-48h]
  char v29; // [esp+1Ch] [ebp-44h]
  _DWORD __b[16]; // [esp+20h] [ebp-40h] BYREF

  if ( !self->_vpCode || !self->_vpCodeCount )
  {
    v4 = -[IODevice name](self, sel_name); /*0x1c72e9*/
    IOLog((int)"%s: No vpcode to run.\n", v4);
    return nullptr; /*0x1c72fd*/
  }
  if ( a4 ) /*0x1c7308*/
  {
    memset(__b, 0, 0x20u); /*0x1c73c8*/
    qmemcpy(&__b[8], a4, 0x20u); /*0x1c73d9*/
  }
  else
  {
    memset(__b, 0, sizeof(__b)); /*0x1c7316*/
  }
  v10 = 0; /*0x1c73de*/
  v27 = 0; /*0x1c73e0*/
  v28 = 0; /*0x1c73e4*/
  v29 = 0; /*0x1c73e8*/
  while ( 2 )
  {
    if ( a3 < 0 || self->_vpCodeCount <= a3 )
    {
      v12 = -[IODevice name](self, sel_name); /*0x1c740a*/
      IOLog((int)"%s: program counter is out of range: 0x%x.\n", v12, a3);
      return nullptr; /*0x1c7421*/
    }
    vpCode = self->_vpCode; /*0x1c742b*/
    v14 = vpCode[a3++]; /*0x1c7431*/
    if ( ((v14 >> 26) & 0x20) != 0 ) /*0x1c7440*/
      v10 = vpCode[a3++]; /*0x1c7442*/
    switch ( v14 >> 26 )
    {
      case 1u:
        v17 = (v14 >> 21) & 0xF; /*0x1c75a5*/
        v10 = __b[v17]; /*0x1c75a8*/
        if ( self->_vpCodeCount <= v10 )
        {
          v24 = __b[v17]; /*0x1c7348*/
          v7 = -[IODevice name](self, sel_name); /*0x1c7354*/
          IOLog((int)"%s: load address is out of range: 0x%x.\n", v7, v24);
          return nullptr; /*0x1c736b*/
        }
        __b[BYTE2(v14) & 0xF] = self->_vpCode[v10]; /*0x1c75cc*/
        continue; /*0x1c75d0*/
      case 2u:
        self->_debug = 1; /*0x1c754b*/
        continue; /*0x1c7552*/
      case 3u:
        v10 = __b[(v14 >> 21) & 0xF]; /*0x1c7624*/
        videoRamAddress = self->_videoRamAddress; /*0x1c762b*/
        if ( !videoRamAddress || self->_videoRamSize <= v10 ) /*0x1c763b*/
          goto LABEL_42; /*0x1c763b*/
        goto LABEL_31; /*0x1c763b*/
      case 4u:
        v19 = HIWORD(v14) & 0xF; /*0x1c7699*/
        v10 = __b[v19]; /*0x1c769c*/
        v18 = self; /*0x1c76a0*/
        if ( self->_vpCodeCount > v10 ) /*0x1c76a9*/
          goto LABEL_36; /*0x1c76a9*/
        v25 = __b[v19]; /*0x1c7398*/
        v9 = -[IODevice name](self, sel_name); /*0x1c73a4*/
        IOLog((int)"%s: store address is out of range: 0x%x.\n", v9, v25);
        return nullptr; /*0x1c73bb*/
      case 5u:
        __b[(v14 >> 11) & 0xF] = __b[HIWORD(v14) & 0xF] + __b[(v14 >> 21) & 0xF]; /*0x1c77c4*/
        continue; /*0x1c77c8*/
      case 6u:
        __b[(v14 >> 11) & 0xF] = __b[(v14 >> 21) & 0xF] - __b[HIWORD(v14) & 0xF]; /*0x1c7830*/
        continue; /*0x1c7834*/
      case 7u:
        v10 = __b[HIWORD(v14) & 0xF]; /*0x1c7720*/
        videoRamAddress = self->_videoRamAddress; /*0x1c7727*/
        if ( !videoRamAddress || self->_videoRamSize <= 4 * v10 ) /*0x1c773e*/
          goto LABEL_42; /*0x1c773e*/
        goto LABEL_43; /*0x1c773e*/
      case 8u:
        __b[(v14 >> 11) & 0xF] = __b[HIWORD(v14) & 0xF] & __b[(v14 >> 21) & 0xF]; /*0x1c787c*/
        continue; /*0x1c7880*/
      case 9u:
        __b[(v14 >> 11) & 0xF] = __b[HIWORD(v14) & 0xF] | __b[(v14 >> 21) & 0xF]; /*0x1c78c8*/
        continue; /*0x1c78cc*/
      case 0xAu:
        __b[(v14 >> 11) & 0xF] = __b[HIWORD(v14) & 0xF] ^ __b[(v14 >> 21) & 0xF]; /*0x1c7914*/
        continue; /*0x1c7918*/
      case 0xBu:
        __b[(v14 >> 11) & 0xF] = __b[(v14 >> 21) & 0xF] << (BYTE2(v14) & 0x1F); /*0x1c7944*/
        continue; /*0x1c7948*/
      case 0xCu:
        __b[(v14 >> 11) & 0xF] = __b[(v14 >> 21) & 0xF] >> (BYTE2(v14) & 0x1F); /*0x1c796e*/
        continue; /*0x1c7972*/
      case 0xDu:
        __b[HIWORD(v14) & 0xF] = __b[(v14 >> 21) & 0xF]; /*0x1c798c*/
        continue; /*0x1c7990*/
      case 0xEu:
        v27 = 0; /*0x1c7998*/
        v28 = 0; /*0x1c799c*/
        v29 = 0; /*0x1c79a0*/
        v10 = __b[(v14 >> 21) & 0xF]; /*0x1c79ac*/
        goto LABEL_59; /*0x1c79ac*/
      case 0xFu:
        v27 = 0; /*0x1c7a18*/
        v28 = 0; /*0x1c7a1c*/
        v29 = 0; /*0x1c7a20*/
        v10 = __b[(v14 >> 21) & 0xF] - __b[HIWORD(v14) & 0xF]; /*0x1c7a38*/
        goto LABEL_59; /*0x1c7a3c*/
      case 0x11u:
        goto LABEL_78;
      case 0x12u:
        if ( !v28 ) /*0x1c7a48*/
          continue; /*0x1c7a48*/
        goto LABEL_78; /*0x1c7a48*/
      case 0x13u:
        if ( !v27 ) /*0x1c7a54*/
          continue; /*0x1c7a54*/
        goto LABEL_78; /*0x1c7a54*/
      case 0x14u:
        if ( !v29 ) /*0x1c7a60*/
          continue; /*0x1c7a60*/
        goto LABEL_78; /*0x1c7a60*/
      case 0x15u:
        if ( v28 ) /*0x1c7a6c*/
          continue; /*0x1c7a6c*/
        goto LABEL_78; /*0x1c7a6c*/
      case 0x16u:
        if ( v27 ) /*0x1c7a78*/
          continue; /*0x1c7a78*/
        goto LABEL_78; /*0x1c7a78*/
      case 0x17u:
        if ( v29 ) /*0x1c7a84*/
          continue; /*0x1c7a84*/
LABEL_78:
        a3 = v14 & 0x3FFFFFF; /*0x1c7a8a*/
        continue; /*0x1c7a92*/
      case 0x18u:
        v21 = __inbyte(v14); /*0x1c7a9a*/
        __b[BYTE2(v14) & 0xF] = v21; /*0x1c7aab*/
        continue; /*0x1c7aaf*/
      case 0x19u:
        __outbyte(v14, __b[HIWORD(v14) & 0xF]); /*0x1c7ac2*/
        _InterlockedIncrement(&dword_1E873C); /*0x1c7ac3*/
        continue; /*0x1c7aca*/
      case 0x1Au:
        v22 = __inword(v14); /*0x1c7ae6*/
        __b[BYTE2(v14) & 0xF] = v22; /*0x1c7af8*/
        continue; /*0x1c7afc*/
      case 0x1Bu:
        __outword(v14, __b[HIWORD(v14) & 0xF]); /*0x1c7b13*/
        _InterlockedIncrement(&dword_1E8740); /*0x1c7b15*/
        continue; /*0x1c7b1c*/
      case 0x1Cu:
        -[IOVPCodeDisplay jumpTo:withInitialSRegs:](self, sel_jumpTo_withInitialSRegs_, v14 & 0x3FFFFFF, &__b[8]); /*0x1c7b51*/
        continue; /*0x1c7b59*/
      case 0x1Du:
        if ( a4 ) /*0x1c7b64*/
          qmemcpy(a4, &__b[8], 0x20u); /*0x1c7b72*/
        return self; /*0x1c7b77*/
      case 0x21u:
      case 0x22u:
        __b[HIWORD(v14) & 0xF] = v10; /*0x1c7570*/
        continue; /*0x1c7574*/
      case 0x23u:
        if ( self->_vpCodeCount <= v10 )
        {
          v6 = -[IODevice name](self, sel_name); /*0x1c732c*/
          IOLog((int)"%s: load address is out of range: 0x%x.\n", v6, v10);
          return nullptr; /*0x1c7343*/
        }
        v15 = BYTE2(v14) & 0xF; /*0x1c7590*/
        videoRamAddress = (unsigned int)self->_vpCode; /*0x1c7593*/
LABEL_32:
        __b[v15] = *(_DWORD *)(videoRamAddress + 4 * v10); /*0x1c7674*/
        continue; /*0x1c767b*/
      case 0x24u:
        v18 = self; /*0x1c7680*/
        if ( self->_vpCodeCount <= v10 )
        {
          v8 = -[IODevice name](self, sel_name); /*0x1c737c*/
          IOLog((int)"%s: store address is out of range: 0x%x.\n", v8, v10);
          return nullptr; /*0x1c7393*/
        }
LABEL_36:
        v18->_vpCode[v10] = __b[(v14 >> 21) & 0xF]; /*0x1c76af*/
        continue; /*0x1c76c4*/
      case 0x25u:
        __b[HIWORD(v14) & 0xF] = v10 + __b[(v14 >> 21) & 0xF]; /*0x1c779a*/
        continue; /*0x1c779e*/
      case 0x26u:
        __b[HIWORD(v14) & 0xF] = v10 - __b[(v14 >> 21) & 0xF]; /*0x1c7806*/
        continue; /*0x1c780a*/
      case 0x27u:
        __b[HIWORD(v14) & 0xF] = __b[(v14 >> 21) & 0xF] - v10; /*0x1c77e6*/
        continue; /*0x1c77ea*/
      case 0x28u:
        __b[HIWORD(v14) & 0xF] = v10 & __b[(v14 >> 21) & 0xF]; /*0x1c7852*/
        continue; /*0x1c7856*/
      case 0x29u:
        __b[HIWORD(v14) & 0xF] = v10 | __b[(v14 >> 21) & 0xF]; /*0x1c789e*/
        continue; /*0x1c78a2*/
      case 0x2Au:
        __b[HIWORD(v14) & 0xF] = v10 ^ __b[(v14 >> 21) & 0xF]; /*0x1c78ea*/
        continue; /*0x1c78ee*/
      case 0x2Bu:
        IODelay(v10); /*0x1c7559*/
        continue; /*0x1c7561*/
      case 0x2Cu:
        videoRamAddress = self->_videoRamAddress; /*0x1c75db*/
        if ( !videoRamAddress || self->_videoRamSize <= v10 ) /*0x1c75eb*/
          goto LABEL_42; /*0x1c75eb*/
LABEL_31:
        v15 = HIWORD(v14) & 0xF; /*0x1c766c*/
        goto LABEL_32; /*0x1c7671*/
      case 0x2Du:
        videoRamAddress = self->_videoRamAddress; /*0x1c76cf*/
        if ( videoRamAddress && self->_videoRamSize > 4 * v10 ) /*0x1c76e6*/
        {
LABEL_43:
          *(_DWORD *)(videoRamAddress + 4 * v10) = __b[(v14 >> 21) & 0xF]; /*0x1c7770*/
          continue; /*0x1c777f*/
        }
LABEL_42:
        v26 = v10 + videoRamAddress; /*0x1c7740*/
        v20 = -[IODevice name](self, sel_name); /*0x1c7751*/
        IOLog((int)"%s: invalid video ram address: 0x%x.\n", v20, v26);
        return nullptr;
      case 0x2Fu:
        v27 = 0; /*0x1c79dc*/
        v28 = 0; /*0x1c79e0*/
        v29 = 0; /*0x1c79e4*/
        v10 = __b[(v14 >> 21) & 0xF] - v10; /*0x1c79f6*/
        goto LABEL_59; /*0x1c79f8*/
      case 0x30u:
        v27 = 0; /*0x1c79fc*/
        v28 = 0; /*0x1c7a00*/
        v29 = 0; /*0x1c7a04*/
        v10 -= __b[(v14 >> 21) & 0xF]; /*0x1c7a10*/
LABEL_59:
        if ( v10 ) /*0x1c79b2*/
        {
          if ( (int)v10 <= 0 ) /*0x1c79c2*/
            v27 = 1; /*0x1c79d0*/
          else
            v28 = 1; /*0x1c79c4*/
        }
        else
        {
          v29 = 1; /*0x1c79b4*/
        }
        continue; /*0x1c79b8*/
      case 0x39u:
        __outbyte(v14, v10); /*0x1c7ad6*/
        _InterlockedIncrement(&dword_1E873C); /*0x1c7ad7*/
        continue; /*0x1c7ade*/
      case 0x3Bu:
        __outword(v14, v10); /*0x1c7b28*/
        _InterlockedIncrement(&dword_1E8740); /*0x1c7b2a*/
        continue; /*0x1c7b31*/
      default:
        v23 = -[IODevice name](self, sel_name); /*0x1c7b89*/
        IOLog((int)"%s: Unrecognized opcode: 0x%08x; pc: 0x%x\n", v23, v14, a3);
        return nullptr; /*0x1c7b9e*/
    }
  }
}
