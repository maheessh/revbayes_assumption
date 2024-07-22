#ifndef Transform_Vector_InvLogit_H
#define Transform_Vector_InvLogit_H

#include "ModelVector.h"
#include "RealPos.h"
#include "RlTypedDistribution.h"
#include "TypeSpec.h"
#include "TransformedVectorDistribution.h"

namespace RevLanguage {

    class Transform_Vector_InvLogit : public TypedDistribution<ModelVector<Probability>> {

    public:
        Transform_Vector_InvLogit( void );
        virtual ~Transform_Vector_InvLogit();

        // Basic utility functions
        Transform_Vector_InvLogit*                                  clone(void) const;                                                                      //!< Clone the object
        static const std::string&                       getClassType(void);                                                                     //!< Get Rev type
        static const TypeSpec&                          getClassTypeSpec(void);                                                                 //!< Get class type spec
        std::string                                     getDistributionFunctionName(void) const;                                                //!< Get the Rev-name for this distribution.
        const TypeSpec&                                 getTypeSpec(void) const;                                                                //!< Get the type spec of the instance
        const MemberRules&                              getParameterRules(void) const;                                                          //!< Get member rules (const)


        // Distribution functions you have to override
        RevBayesCore::TransformedVectorDistribution*    createDistribution(void) const;

    protected:

        void                                            setConstParameter(const std::string& name, const RevPtr<const RevVariable> &var);       //!< Set member variable


    private:
        RevPtr<const RevVariable>                       base_distribution;

    };

}

#endif // Transform_Vector_InvLogit_H
