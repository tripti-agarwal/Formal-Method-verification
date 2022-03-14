abstract sig EndPoint {}
sig Client, Server extends EndPoint {}

abstract sig HTTPEvent {
    from, to : EndPoint
}
run {}