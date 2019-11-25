/** \brief Pide al usuario el ingreso de un dato.
 *
 * \param char* mensaje a mostrar.
 * \param char* dato ingresado.
 * \return int [0] si ocurrio un error.
 *                    [1] si se cargo correctamente.
 */
int getString(char*, char*);

/** \brief Valida que el dato ingresado sea unicamente numerico.
 *
 * \param char* dato ingresado.
 * \return int [0] si el dato es invalido.
 *                    [1] si es valido.
 */
int isOnlyNumber(char*);

/** \brief Valida que el dato ingresado sea unicamente alfabetico.
 *
 * \param char* dato ingresado.
 * \return int [0] si el dato es invalido.
 *                    [1] si es valido.
 */
int isOnlyLetter(char*);

/** \brief Pide el ingreso de un dato unicamente numerico.
 *
 * \param char* mensaje a mostrar.
 * \param char* mensaje a mostrar en caso de ingreso erroneo.
 * \param int* dato ingresado.
 * \return int [0] si ocurrio un error.
 *                    [1] si se cargo correctamente.
 */
int getOnlyNumber(char*, char*, int*);

/** \brief Pide el ingreso de un dato unicamente alfabetico.
 *
 * \param char* mensaje a mostrar.
 * \param char* mensaje a mostrar en caso de ingreso erroneo.
 * \param char* dato ingresado.
 * \return int [0] si ocurrio un error.
 *                    [1] si se cargo correctamente.
 */
int getOnlyLetter(char*, char*, char*);
