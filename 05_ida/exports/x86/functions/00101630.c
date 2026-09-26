/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x101630. */
void *__cdecl memset(void *__b, int __c, size_t __len)
{
  char *v3; // edx
  signed __int32 v4; // ebx
  int v5; // ecx
  int v6; // esi

  v3 = (char *)__b; /*0x101639*/
  v4 = __len; /*0x10163c*/
  v5 = ((__c | (__c << 8)) << 16) | __c | (__c << 8); /*0x101652*/
  if ( (int)__len > 31 ) /*0x101657*/
  {
    if ( ((unsigned __int8)__b & 7) != 0 ) /*0x10179e*/
    {
      v6 = 8 - ((unsigned __int8)__b & 7); /*0x1017ab*/
      switch ( v6 ) /*0x1017b9*/
      {
        case 1: /*0x1017b9*/
          *(_BYTE *)__b = __c; /*0x1018e0*/
          break; /*0x1018e0*/
        case 2: /*0x1017b9*/
          goto LABEL_64;
        case 3: /*0x1017b9*/
          *((_BYTE *)__b + 2) = __c; /*0x1018d8*/
LABEL_64:
          *(_WORD *)__b = __c | ((_WORD)__c << 8); /*0x1018db*/
          break; /*0x1018de*/
        case 4: /*0x1017b9*/
          goto LABEL_59;
        case 5: /*0x1017b9*/
          *((_BYTE *)__b + 4) = __c; /*0x1018d0*/
          goto LABEL_59; /*0x1018d3*/
        case 6: /*0x1017b9*/
          goto LABEL_61;
        case 7: /*0x1017b9*/
          *((_BYTE *)__b + 6) = __c; /*0x1018c4*/
LABEL_61:
          *((_WORD *)__b + 2) = __c | ((_WORD)__c << 8); /*0x1018c7*/
          goto LABEL_59; /*0x1018cb*/
        case 8: /*0x1017b9*/
          goto LABEL_58;
        case 9: /*0x1017b9*/
          *((_BYTE *)__b + 8) = __c; /*0x1018b8*/
          goto LABEL_58; /*0x1018b8*/
        case 10: /*0x1017b9*/
          goto LABEL_56;
        case 11: /*0x1017b9*/
          *((_BYTE *)__b + 10) = __c; /*0x1018ac*/
LABEL_56:
          *((_WORD *)__b + 4) = __c | ((_WORD)__c << 8); /*0x1018af*/
          goto LABEL_58; /*0x1018b3*/
        case 12: /*0x1017b9*/
          goto LABEL_41;
        case 13: /*0x1017b9*/
          *((_BYTE *)__b + 12) = __c; /*0x1018a4*/
          goto LABEL_41; /*0x1018a7*/
        case 14: /*0x1017b9*/
          goto LABEL_53;
        case 15: /*0x1017b9*/
          *((_BYTE *)__b + 14) = __c; /*0x101898*/
LABEL_53:
          *((_WORD *)__b + 6) = __c | ((_WORD)__c << 8); /*0x10189b*/
          goto LABEL_41; /*0x10189f*/
        case 16: /*0x1017b9*/
          goto LABEL_40;
        case 17: /*0x1017b9*/
          *((_BYTE *)__b + 16) = __c; /*0x101890*/
          goto LABEL_40; /*0x101893*/
        case 18: /*0x1017b9*/
          goto LABEL_50;
        case 19: /*0x1017b9*/
          *((_BYTE *)__b + 18) = __c; /*0x101884*/
LABEL_50:
          *((_WORD *)__b + 8) = __c | ((_WORD)__c << 8); /*0x101887*/
          goto LABEL_40; /*0x10188b*/
        case 20: /*0x1017b9*/
          goto LABEL_39;
        case 21: /*0x1017b9*/
          *((_BYTE *)__b + 20) = __c; /*0x10187c*/
          goto LABEL_39; /*0x10187f*/
        case 22: /*0x1017b9*/
          goto LABEL_47;
        case 23: /*0x1017b9*/
          *((_BYTE *)__b + 22) = __c; /*0x101870*/
LABEL_47:
          *((_WORD *)__b + 10) = __c | ((_WORD)__c << 8); /*0x101873*/
          goto LABEL_39; /*0x101877*/
        case 24: /*0x1017b9*/
          goto LABEL_38;
        case 25: /*0x1017b9*/
          *((_BYTE *)__b + 24) = __c; /*0x101868*/
          goto LABEL_38; /*0x10186b*/
        case 26: /*0x1017b9*/
          goto LABEL_44;
        case 27: /*0x1017b9*/
          *((_BYTE *)__b + 26) = __c; /*0x10185c*/
LABEL_44:
          *((_WORD *)__b + 12) = __c | ((_WORD)__c << 8); /*0x10185f*/
          goto LABEL_38; /*0x101863*/
        case 28: /*0x1017b9*/
          goto LABEL_37;
        case 29: /*0x1017b9*/
          *((_BYTE *)__b + 28) = __c; /*0x101854*/
          goto LABEL_37; /*0x101857*/
        case 30: /*0x1017b9*/
          goto LABEL_36;
        case 31: /*0x1017b9*/
          *((_BYTE *)__b + 30) = __c; /*0x10183c*/
LABEL_36:
          *((_WORD *)__b + 14) = __c | ((_WORD)__c << 8); /*0x10183f*/
LABEL_37:
          *((_DWORD *)__b + 6) = v5; /*0x101843*/
LABEL_38:
          *((_DWORD *)__b + 5) = v5; /*0x101846*/
LABEL_39:
          *((_DWORD *)__b + 4) = v5; /*0x101849*/
LABEL_40:
          *((_DWORD *)__b + 3) = v5; /*0x10184c*/
LABEL_41:
          *((_DWORD *)__b + 2) = v5; /*0x10184f*/
LABEL_58:
          *((_DWORD *)__b + 1) = v5; /*0x1018bb*/
LABEL_59:
          *(_DWORD *)__b = v5; /*0x1018be*/
          break; /*0x1018c0*/
        default:
          break;
      }
      v4 = __len - v6; /*0x1018e2*/
      v3 = (char *)__b + v6; /*0x1018e4*/
    }
    v3 = &v3[(v4 & 0x1C) - 32]; /*0x1018eb*/
    switch ( v4 & 0x1C ) /*0x1018f8*/
    {
      case 0: /*0x1018f8*/
        goto LABEL_76;
      case 4: /*0x1018f8*/
        goto LABEL_75;
      case 8: /*0x1018f8*/
        goto LABEL_74;
      case 0xC: /*0x1018f8*/
        goto LABEL_73;
      case 0x10: /*0x1018f8*/
        goto LABEL_72;
      case 0x14: /*0x1018f8*/
        goto LABEL_71;
      case 0x18: /*0x1018f8*/
        goto LABEL_70;
      case 0x1C: /*0x1018f8*/
        while ( 1 ) /*0x101976*/
        {
          *((_DWORD *)v3 + 1) = v5; /*0x101976*/
LABEL_70:
          *((_DWORD *)v3 + 2) = v5; /*0x101979*/
LABEL_71:
          *((_DWORD *)v3 + 3) = v5; /*0x10197c*/
LABEL_72:
          *((_DWORD *)v3 + 4) = v5; /*0x10197f*/
LABEL_73:
          *((_DWORD *)v3 + 5) = v5; /*0x101982*/
LABEL_74:
          *((_DWORD *)v3 + 6) = v5; /*0x101985*/
LABEL_75:
          *((_DWORD *)v3 + 7) = v5; /*0x101988*/
LABEL_76:
          v3 += 32; /*0x10198b*/
          v4 -= 32; /*0x10198e*/
          if ( v4 < 0 ) /*0x101991*/
            break; /*0x101991*/
          *(_DWORD *)v3 = v5; /*0x101974*/
        }
        v4 &= 3u; /*0x101993*/
        break; /*0x101993*/
      default:
        break;
    }
    if ( v4 != 2 ) /*0x101999*/
    {
      if ( v4 <= 2 ) /*0x10199b*/
      {
        if ( v4 != 1 ) /*0x1019a0*/
          return __b; /*0x1019a0*/
        goto LABEL_85; /*0x1019a0*/
      }
      if ( v4 != 3 ) /*0x1019a7*/
        return __b; /*0x1019a7*/
      v3[2] = __c; /*0x1019a9*/
    }
    v3[1] = __c; /*0x1019ac*/
LABEL_85:
    *v3 = __c; /*0x1019af*/
    return __b; /*0x1019af*/
  }
  switch ( __len ) /*0x101669*/
  {
    case 1u: /*0x101669*/
      goto LABEL_85;
    case 2u: /*0x101669*/
      goto LABEL_32;
    case 3u: /*0x101669*/
      *((_BYTE *)__b + 2) = __c; /*0x10178c*/
LABEL_32:
      *(_WORD *)__b = __c | ((_WORD)__c << 8); /*0x10178f*/
      return __b; /*0x101792*/
    case 4u: /*0x101669*/
      goto LABEL_27;
    case 5u: /*0x101669*/
      *((_BYTE *)__b + 4) = __c; /*0x101784*/
      goto LABEL_27; /*0x101787*/
    case 6u: /*0x101669*/
      goto LABEL_29;
    case 7u: /*0x101669*/
      *((_BYTE *)__b + 6) = __c; /*0x101778*/
LABEL_29:
      *((_WORD *)__b + 2) = __c | ((_WORD)__c << 8); /*0x10177b*/
      goto LABEL_27; /*0x10177f*/
    case 8u: /*0x101669*/
      goto LABEL_26;
    case 9u: /*0x101669*/
      *((_BYTE *)__b + 8) = __c; /*0x101768*/
      goto LABEL_26; /*0x101768*/
    case 0xAu: /*0x101669*/
      goto LABEL_24;
    case 0xBu: /*0x101669*/
      *((_BYTE *)__b + 10) = __c; /*0x10175c*/
LABEL_24:
      *((_WORD *)__b + 4) = __c | ((_WORD)__c << 8); /*0x10175f*/
      goto LABEL_26; /*0x101763*/
    case 0xCu: /*0x101669*/
      goto LABEL_9;
    case 0xDu: /*0x101669*/
      *((_BYTE *)__b + 12) = __c; /*0x101754*/
      goto LABEL_9; /*0x101757*/
    case 0xEu: /*0x101669*/
      goto LABEL_21;
    case 0xFu: /*0x101669*/
      *((_BYTE *)__b + 14) = __c; /*0x101748*/
LABEL_21:
      *((_WORD *)__b + 6) = __c | ((_WORD)__c << 8); /*0x10174b*/
      goto LABEL_9; /*0x10174f*/
    case 0x10u: /*0x101669*/
      goto LABEL_8;
    case 0x11u: /*0x101669*/
      *((_BYTE *)__b + 16) = __c; /*0x101740*/
      goto LABEL_8; /*0x101743*/
    case 0x12u: /*0x101669*/
      goto LABEL_18;
    case 0x13u: /*0x101669*/
      *((_BYTE *)__b + 18) = __c; /*0x101734*/
LABEL_18:
      *((_WORD *)__b + 8) = __c | ((_WORD)__c << 8); /*0x101737*/
      goto LABEL_8; /*0x10173b*/
    case 0x14u: /*0x101669*/
      goto LABEL_7;
    case 0x15u: /*0x101669*/
      *((_BYTE *)__b + 20) = __c; /*0x10172c*/
      goto LABEL_7; /*0x10172f*/
    case 0x16u: /*0x101669*/
      goto LABEL_15;
    case 0x17u: /*0x101669*/
      *((_BYTE *)__b + 22) = __c; /*0x101720*/
LABEL_15:
      *((_WORD *)__b + 10) = __c | ((_WORD)__c << 8); /*0x101723*/
      goto LABEL_7; /*0x101727*/
    case 0x18u: /*0x101669*/
      goto LABEL_6;
    case 0x19u: /*0x101669*/
      *((_BYTE *)__b + 24) = __c; /*0x101718*/
      goto LABEL_6; /*0x10171b*/
    case 0x1Au: /*0x101669*/
      goto LABEL_12;
    case 0x1Bu: /*0x101669*/
      *((_BYTE *)__b + 26) = __c; /*0x10170c*/
LABEL_12:
      *((_WORD *)__b + 12) = __c | ((_WORD)__c << 8); /*0x10170f*/
      goto LABEL_6; /*0x101713*/
    case 0x1Cu: /*0x101669*/
      goto LABEL_5;
    case 0x1Du: /*0x101669*/
      *((_BYTE *)__b + 28) = __c; /*0x101704*/
      goto LABEL_5; /*0x101707*/
    case 0x1Eu: /*0x101669*/
      goto LABEL_4;
    case 0x1Fu: /*0x101669*/
      *((_BYTE *)__b + 30) = __c; /*0x1016ec*/
LABEL_4:
      *((_WORD *)__b + 14) = __c | ((_WORD)__c << 8); /*0x1016ef*/
LABEL_5:
      *((_DWORD *)__b + 6) = v5; /*0x1016f3*/
LABEL_6:
      *((_DWORD *)__b + 5) = v5; /*0x1016f6*/
LABEL_7:
      *((_DWORD *)__b + 4) = v5; /*0x1016f9*/
LABEL_8:
      *((_DWORD *)__b + 3) = v5; /*0x1016fc*/
LABEL_9:
      *((_DWORD *)__b + 2) = v5; /*0x1016ff*/
LABEL_26:
      *((_DWORD *)__b + 1) = v5; /*0x10176b*/
LABEL_27:
      *(_DWORD *)__b = v5; /*0x10176e*/
      break; /*0x101770*/
    default:
      return __b;
  }
  return __b; /*0x1019b7*/
}
