/** \brief muestra el menu de opciones al usuario.
 *
 * \param [] char recibe el mensaje a mostrar.
 * \return int retorna la opcion seleccionada.
 *
 */
int menu(char []);

/** \brief pide al usuario el ingreso de un dato.
 *
 * \param [] char recibe el mensaje a mostrar.
 * \param [] char recibe el dato a almacenar.
 * \return void sin retorno.
 *
 */
void getString(char [], char []);

/** \brief pide al usuario el ingreso de un dato alfabetico, realizando la validacion correspondiente.
 *
 * \param [] char recibe el mensaje a mostrar.
 * \param [] char recibe el dato a almacenar.
 * \return void sin retorno.
 *
 */
void getSoloLetras(char [], char []);

/** \brief pide al usuario el ingreso de un numero entero (sin signo), realizando la validacion correspondiente.
 *
 * \param [] char recibe el mensaje a mostrar.
 * \return int retorna el valor ingresado convertido a entero.
 *
 */
int getSoloEnteros(char []);

/** \brief pide al usuario el ingreso de un numero flotante (sin signo), realizando la validacion correspondiente.
 *
 * \param [] char recibe el mensaje a mostrar.
 * \return float retorna el valor ingresado convertido a flotante.
 *
 */
float getSoloFlotantes(char []);
