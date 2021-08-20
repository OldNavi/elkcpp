#include <grpcpp/grpcpp.h>

#include "grpc_utils.h"
#include "sushi_client.h"
#include "keyboard_controller.h"

namespace sushi_controller
{

KeyboardControllerClient::KeyboardControllerClient(const std::string& address)
    : _stub(sushi_rpc::KeyboardController::NewStub(
        grpc::CreateChannel(
            address,
            grpc::InsecureChannelCredentials()
        ))) {}

ControlStatus KeyboardControllerClient::send_note_on(int track_id, int channel, int note, float velocity)
{
    sushi_rpc::NoteOnRequest request;
    sushi_rpc::GenericVoidValue response;
    grpc::ClientContext context;

    request.mutable_track()->set_id(track_id);
    request.set_channel(channel);
    request.set_note(note);
    request.set_velocity(velocity);

    grpc::Status status = _stub.get()->SendNoteOn(&context, request, &response);

    if(!status.ok())
    {
        handle_error(status);
    }
    return to_ext(status);
}

ControlStatus KeyboardControllerClient::send_note_off(int track_id, int channel, int note, float velocity)
{
    sushi_rpc::NoteOffRequest request;
    sushi_rpc::GenericVoidValue response;
    grpc::ClientContext context;

    request.mutable_track()->set_id(track_id);
    request.set_channel(channel);
    request.set_note(note);
    request.set_velocity(velocity);

    grpc::Status status = _stub.get()->SendNoteOff(&context, request, &response);

    if(!status.ok())
    {
        handle_error(status);
    }
    return to_ext(status);
}

ControlStatus KeyboardControllerClient::send_note_aftertouch(int track_id, int channel, int note, float value)
{
    sushi_rpc::NoteAftertouchRequest request;
    sushi_rpc::GenericVoidValue response;
    grpc::ClientContext context;

    request.mutable_track()->set_id(track_id);
    request.set_channel(channel);
    request.set_note(note);
    request.set_value(value);

    grpc::Status status = _stub.get()->SendNoteAftertouch(&context, request, &response);

    if(!status.ok())
    {
        handle_error(status);
    }
    return to_ext(status);
}

ControlStatus KeyboardControllerClient::send_aftertouch(int track_id, int channel, float value)
{
    sushi_rpc::NoteModulationRequest request;
    sushi_rpc::GenericVoidValue response;
    grpc::ClientContext context;

    request.mutable_track()->set_id(track_id);
    request.set_channel(channel);
    request.set_value(value);

    grpc::Status status = _stub.get()->SendAftertouch(&context, request, &response);

    if(!status.ok())
    {
        handle_error(status);
    }
    return to_ext(status);
}

ControlStatus KeyboardControllerClient::send_pitch_bend(int track_id, int channel, float value)
{
    sushi_rpc::NoteModulationRequest request;
    sushi_rpc::GenericVoidValue response;
    grpc::ClientContext context;

    request.mutable_track()->set_id(track_id);
    request.set_channel(channel);
    request.set_value(value);

    grpc::Status status = _stub.get()->SendPitchBend(&context, request, &response);

    if(!status.ok())
    {
        handle_error(status);
    }
    return to_ext(status);
}

ControlStatus KeyboardControllerClient::send_modulation(int track_id, int channel, float value)
{
    sushi_rpc::NoteModulationRequest request;
    sushi_rpc::GenericVoidValue response;
    grpc::ClientContext context;

    request.mutable_track()->set_id(track_id);
    request.set_channel(channel);
    request.set_value(value);

    grpc::Status status = _stub.get()->SendModulation(&context, request, &response);

    if(!status.ok())
    {
        handle_error(status);
    }
    return to_ext(status);
}

std::shared_ptr<KeyboardController> CreateKeyboardController(const std::string& server_address)
{
    return std::move(std::make_shared<KeyboardControllerClient>(server_address));
}

} // namespace sushi_controller

