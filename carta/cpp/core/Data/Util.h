/***
 * Utility class.
 */

#pragma once

#include <State/ObjectManager.h>
#include <QStringList>
#include <vector>



namespace Carta {
namespace State {
class CartaObject;
}

namespace Data {

class Util {

public:

     /**
      * Converts the a string of the form true/false into a bool.
      * @param str the string to convert.
      * @param valid a bool whose value will be set to false if the string is not a valid bool.
      * @return the bool value of the str.
      */
     static bool toBool( const QString str, bool* valid );

     /**
      * Converts a bool to a string representation.
      * @param val a bool to convert;
      * @return a QString representation of the bool.
      */
     static QString toString( bool val );

     /**
      * Returns the singleton object of the given typed class.
      * @return the singleton object with the given typed class.
      */
     template <typename T>
     static T* findSingletonObject( ){
         Carta::State::ObjectManager* objManager = Carta::State::ObjectManager::objectManager();
         T* obj = dynamic_cast<T*>(objManager->getObject( T::CLASS_NAME ));
         if ( obj == NULL ){
             obj = objManager->createObject<T>();
         }
         return obj;
     }

     /**
      * Posts the error message, if one exists, and returns the last valid value, if one exists
      * in the case of an error.
      * @param errorMsg {QString} an error message if one occurred; otherwise an empty string.
      * @param revertValue {QString} a string representation of the last valid value
      */
     static void commandPostProcess( const QString& errorMsg );

     /**
      * Returns true if the lists have the same length and elements; false otherwise.
      * @param list1 - {QStringList} the first list to compare.
      * @param list2 - {QStringList} the second list to compare.
      * @return true if the lists are equal; false otherwise.
      */
     static bool isListMatch( const QStringList& list1, const QStringList& list2 );

     /**
      * Round the value to the given number of significant digits.
      * @param value the value to round.
      * @param digits the number of significant digits.
      * @return the rounded value.
      */
     static double roundToDigits(double value, int digits);

     /**
      * Converts a string containing doubles with a separator between them to a vector.
      * @param sep {QString} the separator.
      * @param s {QString} a string containing doubles separated by a delimiter.
      * @return a vector of doubles.
      */
     static std::vector < double > string2VectorDouble( QString s, QString sep = " " );

     static const QString PREFERENCES;

private:
    Util();
    virtual ~Util();
    static const QString TRUE;
    static const QString FALSE;

};
}
}
