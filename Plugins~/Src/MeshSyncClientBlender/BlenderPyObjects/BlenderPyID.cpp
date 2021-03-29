#include "pch.h"

#include "BlenderPyID.h"
#include "BlenderPyCommon.h" //call, etc

namespace blender
{

extern bContext *g_context;


StructRNA* BlenderPyID::s_type;
PropertyRNA* BlenderPyID_is_updated;
PropertyRNA* BlenderPyID_is_updated_data;
FunctionRNA* BlenderPyID_evaluated_get;


const char *BlenderPyID::name() const { return m_ptr->name + 2; }
bool BlenderPyID::is_updated() const
{
#if BLENDER_VERSION < 280
    return get_bool(m_ptr, BID_is_updated);
#else
    return true;
#endif

}
bool BlenderPyID::is_updated_data() const
{
#if BLENDER_VERSION < 280
    return get_bool(m_ptr, BID_is_updated_data);
#else
    return true;
#endif
}

ID* blender::BlenderPyID::evaluated_get(Depsgraph* depsgraph)
{
    return call<ID, ID*, Depsgraph*>(m_ptr, BlenderPyID_evaluated_get, depsgraph);
}



} // namespace blender
