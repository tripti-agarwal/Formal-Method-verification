abstract sig EndPoint {}
sig Client, Server extends EndPoint {}

abstract sig HTTPEvent {
    from, to : EndPoint
}
sig Request extends HTTPEvent {
    response:Response
}
sig Response extends HTTPEvent {}

fact {
    Request.from + Response.to in Client
    Response.from + Request.to in Server
    all r:Response | one response.r
    all r:Response | r.to = response.r.from and r.from = response.r.to
}

run {
   some response
}
check {
    all r: Request | r.to = r.response.from
}