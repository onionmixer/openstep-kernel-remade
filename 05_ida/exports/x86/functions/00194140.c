/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x194140. */
int __cdecl sub_194140(int a1)
{
  id v1; // esi
  const char *v2; // ebx
  KernStringList *v3; // eax
  const char *v4; // eax
  const char *v5; // ebx
  Class v6; // edi
  int v7; // edx
  char v8; // dl
  id v9; // eax
  id v10; // eax
  KernDevice *v11; // eax
  KernDevice *v12; // eax
  Class v13; // eax
  objc_class *v14; // eax
  int dev_port; // eax
  KernDeviceDescription *v16; // eax
  id v17; // eax
  id v18; // eax
  Class Class; // [esp+10h] [ebp-30h]
  char *name; // [esp+14h] [ebp-2Ch]
  const char *v22; // [esp+18h] [ebp-28h]
  const char *v23; // [esp+1Ch] [ebp-24h]
  char v24; // [esp+20h] [ebp-20h]
  int v25; // [esp+24h] [ebp-1Ch]
  unsigned int i; // [esp+28h] [ebp-18h]
  id v27; // [esp+2Ch] [ebp-14h]
  KernDevice *v28; // [esp+30h] [ebp-10h]
  id v29; // [esp+34h] [ebp-Ch]
  id v30; // [esp+38h] [ebp-8h]
  KernStringList *v31; // [esp+3Ch] [ebp-4h]

  v1 = nullptr; /*0x19414c*/
  v28 = nullptr; /*0x19414e*/
  v27 = nullptr; /*0x194155*/
  v24 = 0; /*0x19415c*/
  name = (char *)IOMalloc(0x80u); /*0x19416a*/
  v29 = +[IOConfigTable newForConfigData:](aIoconfigtable, sel_newForConfigData_, a1); /*0x19417f*/
  v30 = objc_msgSend(v29, sel_valueForStringKey_, aServerName_0); /*0x194196*/
  v2 = (const char *)objc_msgSend(v29, sel_valueForStringKey_, aClassNames); /*0x1941ad*/
  if ( !v2 ) /*0x1941b4*/
    v2 = (const char *)objc_msgSend(v29, sel_valueForStringKey_, aDriverName_0); /*0x1941ca*/
  v3 = +[Object alloc](aKernstringlist, sel_alloc); /*0x1941e2*/
  v31 = -[KernStringList initWithWhitespaceDelimitedString:](v3, sel_initWithWhitespaceDelimitedString_); /*0x1941f2*/
  IOFree((int)v2, strlen(v2) + 1); /*0x194209*/
  v4 = (const char *)objc_msgSend(v29, sel_valueForStringKey_, aBusType_0); /*0x19421d*/
  v22 = v4; /*0x194222*/
  if ( v4 && *v4 ) /*0x19422c*/
  {
    v23 = v4; /*0x19424b*/
    sprintf(name, "%sKernBus", v4); /*0x19425b*/
  }
  else
  {
    v23 = aEisa_3; /*0x194231*/
    sprintf(name, "%sKernBus", aEisa_3); /*0x194238*/
  }
  Class = objc_getClass(name); /*0x194269*/
  if ( !Class ) /*0x194271*/
  {
    Class = (Class)defaultBusClass; /*0x194278*/
    v23 = aEisa_4; /*0x19427b*/
  }
  v25 = 0; /*0x194282*/
  for ( i = 0; ; ++i ) /*0x194289*/
  {
    if ( i >= -[KernStringList count](v31, sel_count) ) /*0x1942a7*/
      goto LABEL_42; /*0x1942a7*/
    v5 = -[KernStringList stringAt:](v31, sel_stringAt_, i); /*0x1942c0*/
    v6 = objc_getClass(v5); /*0x1942c8*/
    if ( !v6 ) /*0x1942cf*/
      break; /*0x1942cf*/
    if ( !v24 ) /*0x1942d9*/
    {
      if ( v30 ) /*0x1942df*/
      {
        v7 = +[IODevice driverKitVersionForDriverNamed:](aIodevice_0, sel_driverKitVersionForDriverNamed_, v30); /*0x1942f6*/
        if ( v7 == -1 ) /*0x1942fe*/
          v7 = 310; /*0x194300*/
        if ( v7 > 310 ) /*0x19430b*/
        {
          v8 = 1; /*0x194334*/
        }
        else
        {
          IOLog(aWarningDriverS); /*0x194317*/
          IOLog(aDriverSCouldNo); /*0x194325*/
          v8 = 0; /*0x19432a*/
        }
        if ( !v8 ) /*0x19433b*/
          goto LABEL_53; /*0x19433b*/
      }
      v24 = 1; /*0x194341*/
    }
    if ( (unsigned __int8)-[objc_class configureDriverWithTable:](Class, sel_configureDriverWithTable_, v29) ) /*0x194358*/
    {
      v25 = 1; /*0x19423c*/
LABEL_42:
      IOFree((int)name, 128); /*0x194570*/
      -[KernStringList free](v31, sel_free); /*0x194588*/
      if ( v30 ) /*0x194594*/
        objc_msgSend(v29, sel_freeString_, v30); /*0x1945a4*/
      if ( v22 ) /*0x1945b0*/
        objc_msgSend(v29, sel_freeString_, v22); /*0x1945c0*/
      if ( v25 ) /*0x1945cc*/
        return 1; /*0x1945d3*/
      objc_msgSend(v29, sel_free); /*0x1945e2*/
      objc_msgSend(v27, sel_free); /*0x1945f1*/
      objc_msgSend(v1, sel_free); /*0x1945fd*/
LABEL_64:
      -[KernDevice free](v28, sel_free); /*0x1946c5*/
      return 0; /*0x1946cf*/
    }
    v9 = -[objc_class deviceStyle](v6, sel_deviceStyle); /*0x19436c*/
    if ( v9 ) /*0x194378*/
    {
      if ( (unsigned int)v9 > 2 ) /*0x19437d*/
      {
        IOLog(aInvalidStyleFo); /*0x194512*/
        goto LABEL_53; /*0x194512*/
      }
      v16 = +[Object alloc](aKerndevicedesc, sel_alloc); /*0x1944ba*/
      v17 = -[KernDeviceDescription initFromConfigTable:](v16, sel_initFromConfigTable_); /*0x1944c5*/
      v1 = v17; /*0x1944ca*/
      if ( !v17 ) /*0x1944d1*/
        goto LABEL_53; /*0x1944d1*/
      v18 = objc_msgSend(&aIodevicedescri_0, sel_alloc); /*0x1944ea*/
      v27 = objc_msgSend(v18, sel__initWithDelegate_); /*0x1944fa*/
      if ( !v27 ) /*0x194502*/
        goto LABEL_53; /*0x194502*/
    }
    else
    {
      v1 = -[objc_class deviceDescriptionFromConfigTable:](Class, sel_deviceDescriptionFromConfigTable_, v29); /*0x19439b*/
      if ( !v1 ) /*0x1943a2*/
      {
        IOLog(aConfiguredrive_0); /*0x19460e*/
        goto LABEL_53; /*0x19460e*/
      }
      if ( !objc_msgSend(v1, sel_bus) ) /*0x1943af*/
        objc_msgSend(v1, sel_setBus_, defaultBus); /*0x1943ca*/
      v10 = objc_msgSend(v1, sel_bus); /*0x1943e0*/
      if ( !objc_msgSend(v10, sel_allocateResourcesForDeviceDescription_) ) /*0x1943f7*/
      {
        IOLog(aConfiguredrive_1); /*0x194616*/
        goto LABEL_53; /*0x194616*/
      }
      v11 = +[Object alloc](aKerndevice, sel_alloc); /*0x194410*/
      v12 = -[KernDevice initWithDeviceDescription:](v11, sel_initWithDeviceDescription_); /*0x19441b*/
      v28 = v12; /*0x194420*/
      if ( !v12 ) /*0x194428*/
      {
        IOLog(aConfiguredrive_2); /*0x19461e*/
        goto LABEL_53; /*0x194626*/
      }
      objc_msgSend(v1, sel_setDevice_, v12); /*0x194436*/
      sprintf(name, "IO%sDeviceDescription", v23); /*0x194448*/
      v13 = objc_getClass(name); /*0x194451*/
      v14 = -[objc_class alloc](v13, sel_alloc); /*0x194466*/
      v27 = -[objc_class _initWithDelegate:](v14, sel__initWithDelegate_); /*0x194476*/
      if ( !v27 ) /*0x19447e*/
        goto LABEL_53; /*0x19447e*/
      dev_port = create_dev_port((int)v28); /*0x194488*/
      objc_msgSend(v27, sel_setDevicePort_, dev_port); /*0x19449a*/
    }
    if ( (unsigned __int8)-[objc_class respondsTo:](v6, sel_respondsTo_, sel_probe_) ) /*0x19452a*/
    {
      if ( !+[IODevice addLoadedClass:description:](aIodevice_0, sel_addLoadedClass_description_, v6, v27) ) /*0x194555*/
        ++v25; /*0x194563*/
    }
    else
    {
      IOLog(aConfiguredrive); /*0x194539*/
    }
  }
  IOLog(aConfiguredrive_3); /*0x19462e*/
  IOLog(aDriverSCouldNo_0); /*0x19463c*/
LABEL_53:
  if ( v30 ) /*0x194648*/
    objc_msgSend(v29, sel_freeString_, v30); /*0x194658*/
  if ( v22 ) /*0x194664*/
    objc_msgSend(v29, sel_freeString_, v22); /*0x194674*/
  if ( v29 ) /*0x194680*/
    objc_msgSend(v29, sel_free); /*0x19468c*/
  if ( v27 ) /*0x194698*/
    objc_msgSend(v27, sel_free); /*0x1946a4*/
  if ( v1 ) /*0x1946ae*/
    objc_msgSend(v1, sel_free); /*0x1946b7*/
  if ( v28 ) /*0x1946c3*/
    goto LABEL_64; /*0x1946c3*/
  return 0; /*0x1946d9*/
}
