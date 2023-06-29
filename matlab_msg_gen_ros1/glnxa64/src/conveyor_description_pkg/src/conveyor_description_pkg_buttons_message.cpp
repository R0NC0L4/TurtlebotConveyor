// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for conveyor_description_pkg/buttons
#include "boost/date_time.hpp"
#include "boost/shared_array.hpp"
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4244)
#pragma warning(disable : 4265)
#pragma warning(disable : 4458)
#pragma warning(disable : 4100)
#pragma warning(disable : 4127)
#pragma warning(disable : 4267)
#pragma warning(disable : 4068)
#pragma warning(disable : 4245)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wshadow"
#endif //_MSC_VER
#include "ros/ros.h"
#include "conveyor_description_pkg/buttons.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class CONVEYOR_DESCRIPTION_PKG_EXPORT conveyor_description_pkg_msg_buttons_common : public MATLABROSMsgInterface<conveyor_description_pkg::buttons> {
  public:
    virtual ~conveyor_description_pkg_msg_buttons_common(){}
    virtual void copy_from_struct(conveyor_description_pkg::buttons* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const conveyor_description_pkg::buttons* msg, MultiLibLoader loader, size_t size = 1);
};
  void conveyor_description_pkg_msg_buttons_common::copy_from_struct(conveyor_description_pkg::buttons* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //angle
        const matlab::data::TypedArray<float> angle_arr = arr["Angle"];
        msg->angle = angle_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Angle' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Angle' is wrong type; expected a single.");
    }
    try {
        //rb
        const matlab::data::TypedArray<bool> rb_arr = arr["Rb"];
        msg->rb = rb_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Rb' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Rb' is wrong type; expected a logical.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T conveyor_description_pkg_msg_buttons_common::get_arr(MDFactory_T& factory, const conveyor_description_pkg::buttons* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Angle","Rb"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("conveyor_description_pkg/buttons");
    // angle
    auto currentElement_angle = (msg + ctr)->angle;
    outArray[ctr]["Angle"] = factory.createScalar(currentElement_angle);
    // rb
    auto currentElement_rb = (msg + ctr)->rb;
    outArray[ctr]["Rb"] = factory.createScalar(static_cast<bool>(currentElement_rb));
    }
    return std::move(outArray);
  } 
class CONVEYOR_DESCRIPTION_PKG_EXPORT conveyor_description_pkg_buttons_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~conveyor_description_pkg_buttons_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          conveyor_description_pkg_buttons_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<conveyor_description_pkg::buttons,conveyor_description_pkg_msg_buttons_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         conveyor_description_pkg_buttons_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<conveyor_description_pkg::buttons,conveyor_description_pkg::buttons::ConstPtr,conveyor_description_pkg_msg_buttons_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         conveyor_description_pkg_buttons_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<conveyor_description_pkg::buttons,conveyor_description_pkg_msg_buttons_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(conveyor_description_pkg_msg_buttons_common, MATLABROSMsgInterface<conveyor_description_pkg::buttons>)
CLASS_LOADER_REGISTER_CLASS(conveyor_description_pkg_buttons_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1