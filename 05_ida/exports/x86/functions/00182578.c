/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x182578. */
int __cdecl kern_IOUnloadDriver(int a1, int a2)
{
  id v3; // ebx
  const char *v4; // esi
  Class Class; // eax

  if ( !a1 ) /*0x182581*/
    return -705; /*0x182583*/
  v3 = +[IOConfigTable newForConfigData:](aIoconfigtable, sel_newForConfigData_, a2); /*0x1825a7*/
  v4 = (const char *)objc_msgSend(v3, sel_valueForStringKey_, aDriverName); /*0x1825bb*/
  Class = objc_getClass(v4); /*0x1825be*/
  if ( Class ) /*0x1825c8*/
  {
    -[objc_class unregisterClass:](Class, sel_unregisterClass_, Class); /*0x1825f9*/
    if ( v3 ) /*0x182603*/
      objc_msgSend(v3, sel_free); /*0x18260d*/
    return 0; /*0x182612*/
  }
  else
  {
    IOLog(aIounloaddriver); /*0x1825d0*/
    if ( v3 ) /*0x1825da*/
      objc_msgSend(v3, sel_free); /*0x1825e4*/
    return -706; /*0x1825e9*/
  }
}
