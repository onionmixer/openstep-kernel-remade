/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x193f34. */
int probeNativeDevices()
{
  int BootConfigString; // eax
  const char *v1; // eax
  const char *v2; // ebx
  const char *v3; // eax
  Class Class; // eax
  int j; // esi
  id v6; // eax
  int v7; // eax
  char *v9; // [esp+Ch] [ebp-10h]
  id v10; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]
  int k; // [esp+14h] [ebp-8h]
  int v13; // [esp+18h] [ebp-4h] BYREF

  sub_194890(); /*0x193f3d*/
  v9 = (char *)IOMalloc(128); /*0x193f4c*/
  for ( i = 1; ; ++i ) /*0x193f4f*/
  {
    BootConfigString = findBootConfigString(i); /*0x193f60*/
    if ( !BootConfigString ) /*0x193f6a*/
      break; /*0x193f6a*/
    v10 = +[IOConfigTable newForConfigData:](aIoconfigtable, sel_newForConfigData_, BootConfigString); /*0x193f84*/
    v1 = (const char *)objc_msgSend(v10, sel_valueForStringKey_, aFamily); /*0x193f97*/
    v2 = v1; /*0x193f9c*/
    if ( v1 ) /*0x193fa3*/
    {
      if ( !strcmp(v1, aBus_0) ) /*0x193fb4*/
      {
        v3 = (const char *)objc_msgSend(v10, sel_valueForStringKey_, aBusClass); /*0x193fc8*/
        Class = objc_getClass(v3); /*0x193fce*/
        -[objc_class probeBus:](Class, sel_probeBus_, v10); /*0x193fdf*/
      }
      objc_msgSend(v10, sel_freeString_, v2); /*0x193ff3*/
    }
  }
  defaultBusClass = +[KernBus lookupBusClassWithName:](aKernbus, sel_lookupBusClassWithName_, aEisa_0); /*0x19401c*/
  if ( !defaultBusClass ) /*0x194026*/
  {
    sprintf(v9, "Missing %s kernel bus class", aEisa_1); /*0x194036*/
    panic(v9); /*0x19403f*/
  }
  defaultBus = +[KernBus lookupBusInstanceWithName:busId:](aKernbus, sel_lookupBusInstanceWithName_busId_, aEisa_2, 0); /*0x194061*/
  if ( eisa_id(0, &v13) ) /*0x19406c*/
  {
    printf("CPU:\tEISA id %08x\n", v13); /*0x194081*/
    for ( j = 1; j <= 15; ++j ) /*0x194086*/
    {
      if ( eisa_id(j, &v13) ) /*0x194092*/
        printf("slot %x:\tEISA id %08x\n", j, v13); /*0x1940a8*/
    }
    led_msg(aNext_1); /*0x1940bb*/
    is_ISA = 0; /*0x1940c0*/
  }
  else
  {
    printf("ISA bus\n"); /*0x1940d1*/
    is_ISA = 1; /*0x1940d6*/
  }
  v6 = +[IODevice driverKitVersion](aIodevice_0, sel_driverKitVersion); /*0x1940ee*/
  printf("DriverKit version %d\n", v6); /*0x1940f9*/
  for ( k = 1; ; ++k ) /*0x1940fe*/
  {
    v7 = findBootConfigString(k); /*0x19410c*/
    if ( !v7 ) /*0x194116*/
      break; /*0x194116*/
    sub_194140(v7); /*0x194119*/
  }
  return IOFree(v9, 128); /*0x194139*/
}
