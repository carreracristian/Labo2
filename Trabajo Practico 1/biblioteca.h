/** \brief muestra el menu de opciones de la calculadora.
 *
 * \param a float muestra el valor actual del primer numero en el menu.
 * \param b float muestra el valor actual del segundo numero en el menu.
 * \return int devuelve la opcion seleccionada.
 *
 */
int menuDeOpciones(float a, float b);



/** \brief pide un numero y retorna el resultado.
 *
 * \param mensaje[] char mensaje que se muestra al pedir el numero.
 * \return float devuelve el numero ingresado.
 *
 */
float pedirNumero(char mensaje[]);



/** \brief opera la suma de dos numeros y devuelve el resultado.
 *
 * \param a float se asigna al primer numero.
 * \param b float se asigna al segundo numero.
 * \return float retorna resultado de la suma.
 *
 */
float operacionSumar(float a, float b);



/** \brief opera la resta de dos numeros y devuelve el resultado.
 *
 * \param a float se asigna al primer numero.
 * \param b float se asigna al segundo numero.
 * \return float retorna resultado de la resta.
 *
 */
float operacionRestar(float a, float b);



/** \brief opera la division entre dos numeros y devuelve el resultado.
 *
 * \param a float se asigna al primer numero.
 * \param b float se asigna al segundo numero.
 * \return float retorna resultado de la division.
 *
 */
float operacionDividir(float a, float b);



/** \brief opera la multiplicacion entre dos numeros y devuelve el resultado.
 *
 * \param a float se asigna al primer numero.
 * \param b float se asigna al segundo numero.
 * \return float retorna resultado de la multiplicacion.
 *
 */
float operacionMultiplicar(float a, float b);



/** \brief opera el factorial de un numero y devuelve el resultado.
 *
 * \param a float se asigna al numero.
 * \return int devuelve el factorial.
 *
 */
int operacionFactorial(float a);



/** \brief informa el resultado de la suma de los numeros ingresados.
 *
 * \param a float se asigna al primer numero.
 * \param b float se asigna al segundo numero.
 * \param c float se asigna al resultado de la suma.
 * \return void no retorna valor.
 *
 */
void informarSuma(float a, float b, float c);



/** \brief informa el resultado de la resta de los numeros ingresados.
 *
 * \param a float se asigna al primer numero.
 * \param b float se asigna al segundo numero.
 * \param c float se asigna al resultado de la resta.
 * \return void no retorna valor.
 *
 */
void informarResta(float a, float b, float c);



/** \brief informa: el resultado de la division entre los numeros ingresados, o un error si el segundo numero es 0 (cero).
 *
 * \param a float se asigna al primer numero.
 * \param b float se asigna al segundo numero.
 * \param c float se asigna al resultado de la division.
 * \return void no retorna valor.
 *
 */
void informarDivision(float a, float b, float c);



/** \brief informa el resultado de la multiplicacion entre los numeros ingresados.
 *
 * \param a float se asigna al primer numero.
 * \param b float se asigna al segundo numero.
 * \param c float se asigna al resultado de la multiplicacion.
 * \return void no retorna valor.
 *
 */
void informarMultiplicacion(float a, float b, float c);



/** \brief informa el factorial de cada numero ingresado, tomando en cuenta los posibles casos de error.
 *
 * \param a float se asigna al primer numero.
 * \param b float se asigna al segundo numero.
 * \param c float se asigna al factorial del primer numero.
 * \param d float se asigna al factorial del segundo numero.
 * \return void no retorna valor.
 *
 */
void informarFactorial(float a, float b, float c, float d);
