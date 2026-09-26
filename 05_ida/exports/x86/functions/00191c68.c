/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x191c68. */
int sub_191C68()
{
  id *v0; // eax
  id *v1; // edi
  int v2; // esi
  id i; // eax
  id *v4; // ebx
  id v6; // [esp+10h] [ebp-A4h] BYREF
  _BYTE v7[80]; // [esp+14h] [ebp-A0h] BYREF
  char v8[80]; // [esp+64h] [ebp-50h] BYREF

  v0 = +[SCSIDisk requiredProtocols](aScsidisk_0, sel_requiredProtocols); /*0x191c82*/
  v1 = v0; /*0x191c87*/
  if ( !v0 || !*v0 ) /*0x191c94*/
    return 1; /*0x191d2a*/
  v2 = 0; /*0x191c9d*/
  for ( i = +[IODevice lookupByObjectNumber:deviceKind:deviceName:]( /*0x191cc5*/
              aIodevice_0,
              sel_lookupByObjectNumber_deviceKind_deviceName_,
              0,
              v7,
              v8);
        !i || i == (id)-727;
        i = +[IODevice lookupByObjectNumber:deviceKind:deviceName:](
              aIodevice_0,
              sel_lookupByObjectNumber_deviceKind_deviceName_,
              v2,
              v7,
              v8) )
  {
    if ( !IOGetObjectForDeviceName(v8, (int)&v6) ) /*0x191ce6*/
    {
      if ( !*v1 ) /*0x191cf5*/
        return 1; /*0x191cf5*/
      v4 = v1; /*0x191cf7*/
      while ( (unsigned __int8)objc_msgSend(v6, sel_conformsTo_, *v4) ) /*0x191d17*/
      {
        if ( !*++v4 ) /*0x191d1c*/
          return 1; /*0x191d1f*/
      }
    }
    ++v2; /*0x191d34*/
  }
  return 0; /*0x191d44*/
}
