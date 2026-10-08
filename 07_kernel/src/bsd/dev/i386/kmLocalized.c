/*
 * kmLocalized.c (plan 340).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes (D024,
 * original object __text [0x197988, 0x1979e4), __data 0x1e3e94 872 B).
 * plan 340: kept as C -- the original kernel has no Objective-C module
 * record attributable to this file, the body needs no Objective-C syntax,
 * and the C build matches; the original's compiler language is inferred
 * (Darwin 0.1 names the file kmLocalized.m).
 * The text is nearly the same as Darwin 0.1
 * kernel/bsd/dev/i386/kmLocalized.m; kept as project-authored
 * under D027/D030, without Darwin's notices (license judgement: D017).
 */

#import <driverkit/i386/driverTypesPrivate.h>
#import <bsd/dev/kmreg_com.h>
#import <bsd/dev/i386/km.h>
#import <bsd/dev/i386/BasicConsole.h>

const char *kmLocalizedStrings[][L_NUM_LANGUAGE] = {
{
"Restarting the computer...\n",			// L_ENGLISH
"Redemarrage en cours...\n",			// L_FRENCH
"Starte neu...\n",				// L_GERMAN
"Reinicializando...\n",				// L_SPANISH
"Riavvio...\n",					// L_ITALIAN
"Startar om...\n",				// L_SWEDISH
NULL,						// L_JAPANESE
},

{ 
"Please wait until it's safe\n"			// L_ENGLISH
"to turn off the computer.\n",
"Veuillez patienter avant\n"			// L_FRENCH
"d'eteindre votre ordinateur.\n",
"Bitte warten Sie, bis Sie Ihren Computer\n"	// L_GERMAN
"sicher ausschalten koennen.\n",
"Espere hasta que sea seguro\n"			// L_SPANISH
"apagar el ordenador.\n",
"Prima di spegnere il computer,\n"		// L_ITALIAN
"attendi la conferma.\n",
"Vanta tills det ar sakert att stanga av datorn.\n", // L_SWEDISH
NULL,						// L_JAPANESE
},

{
"It's safe to turn off the computer.\n",	// L_ENGLISH
"Vous pouvez maintenant eteindre\n"
"votre ordinateur en toute securite.\n",	// L_FRENCH
"Jetzt koennen Sie Ihren Computer\n"
"sicher ausschalten.\n",			// L_GERMAN
"Ahora es seguro apagar el ordenador.\n",	// L_SPANISH
"Ora puoi spegnere il computer.\n",		// L_ITALIAN
"Nu ar det sakert att stanga av datorn.\n",	// L_SWEDISH
NULL,						// L_JAPANESE
},

{
"Please wait...",				// L_ENGLISH
NULL,						// L_FRENCH
NULL,						// L_GERMAN
NULL,						// L_SPANISH
NULL,						// L_ITALIAN
NULL,						// L_SWEDISH
NULL,						// L_JAPANESE
},

{ NULL }					// END

};

const char *
kmLocalizeString(
    const char *str
)
{
    int i, lang;
    const char *newStr;
    
    lang = glLanguage;
    if (lang < 0 || lang >= L_NUM_LANGUAGE)
	lang = L_ENGLISH;
	
    for (i = 0; kmLocalizedStrings[i][0] != NULL; i++) {
	if (strcmp(kmLocalizedStrings[i][0], str) == 0) {
	    if ((newStr = kmLocalizedStrings[i][lang]) != NULL)
		return newStr;
	    break;
	}
    }
    return str;
}
