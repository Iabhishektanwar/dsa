import csv
import matplotlib.pyplot as plt


class Station:  # tube station
    def __init__(self, name, hub_id, station_id, latitude, longitude):
        self.name = name  # not unique: there are often several stations under one roof, each defined by station-line
        # tuple
        self.hub_id = hub_id
        self.station_id = station_id  # tuple(hub id, line id)
        self.latitude = latitude  # latitude
        self.longitude = longitude  # longitude
        self.visited = False
        self.neighbours = []  # station_id
        self.connections = []  # connection_id


class Connection:
    def __init__(self, connection_id, station1, station2, time, line):
        self.connection_id = connection_id
        self.station1 = station1  # id-tuple of the station
        self.station2 = station2  # id-tuple of the station
        self.time = time  # in minutes
        self.line = line  # int
        self.coordinates = None


class Graph:  # tube network
    def __init__(self):
        # self.directed = directed
        self.all_stations = all_stations
        self.all_connections = all_connections

    def getStation(self, station_id):
        return self.all_stations[station_id]

    def getNeighbours(self, station_id):
        v = self.all_stations[station_id]
        return [self.all_stations[id_number] for id_number in v.neighbours]

    def getCoordinates(self, connection, from_id):  # type Graph, type Connection, tuple representing station.station_id
        s1 = self.getStation(connection.station1)  # type Station
        s2 = self.getStation(connection.station2)  # type Station
        if from_id == s1.station_id:
            connection.coordinates = {'lat_from': s1.latitude, 'long_from': s1.longitude, 'lat_to': s2.latitude,
                                      'long_to': s2.longitude}
        if from_id == s2.station_id:
            connection.coordinates = {'lat_from': s2.latitude, 'long_from': s2.longitude, 'lat_to': s1.latitude,
                                      'long_to': s1.longitude}
        return connection.coordinates

    # def getConnectionFrom(self, vx):  # input: station > ids of corresponding connections. Output: type Connections
    #     connections_selected = [self.all_connections[connection_id] for connection_id in vx.connections]
    #     return connections_selected

    def getConnectionBetween(self, station1, station2):
        if station1.station_id not in station2.neighbours:
            return 'No direct link between given stations'
        else:
            for connection_id in station1.connections:
                connection = self.all_connections[connection_id]
                if station2.station_id in [connection.station2, connection.station1] and station1.station_id in \
                        [connection.station2, connection.station1]:
                    return connection

    @staticmethod
    def checkInputs(station_name):
        for station_info in stations:
            if station_info['name'] == station_name:
                return 1
        return 0

    def findRoute(self, start, end):
        # Dijkstra algorithm implementation to navigate the London tube
        # input: names of tube stations in string format, case-sensitive

        # 1. Transverse stations
        # =========================
        # input turned into corresponding stations:
        if Graph.checkInputs(start):
            starting_station_id = int(CSV.getStationIdFromName(start))  # 198
            for station_id in self.all_stations:
                if station_id[0] == starting_station_id:
                    start = self.getStation(station_id)
                    break
        else:
            return 'Start station does not exist.'
        if Graph.checkInputs(end):
            ending_station_id = int(CSV.getStationIdFromName(end))
            for station_id in self.all_stations:
                if station_id[0] == ending_station_id:
                    end = self.getStation(station_id)
                    break
        else:
            return 'End station does not exist.'

        # variables outside the main for-loop
        unvisited = dict([(station_hub_id, 1000) for (station_hub_id, time) in self.all_stations.items()])
        unvisited[start.station_id] = 0  # (198, 11)
        visited = []
        current = start
        routes = {current.station_id: [{'name': current.name, 'station_id': current.station_id}]}

        # latest = None

        # traverse stations:
        while not end.visited:

            for neighbour_id in current.neighbours:
                neighbour = self.getStation(neighbour_id)
                connection_to_neighbour = self.getConnectionBetween(current, neighbour)  # []
                if connection_to_neighbour.time == time_to_change_lines and (
                        connection_to_neighbour.station1 == start.station_id or
                        connection_to_neighbour.station2 == end.station_id):
                    connection_to_neighbour.time = 0

                    # store the quickest path to each visited station in a dict called Routes:
                if neighbour.station_id in unvisited:
                    if unvisited[neighbour.station_id] > (unvisited[current.station_id] + connection_to_neighbour.time):
                        unvisited[neighbour.station_id] = unvisited[current.station_id] + connection_to_neighbour.time
                        routes[neighbour.station_id] = routes[current.station_id][:]
                        routes[neighbour.station_id].append(
                            {"name": neighbour.name, 'station_id': neighbour.station_id})

            # make sure visited stations will not be visited again. Close the loop by changing Current:
            current.visited = True
            visited.append(unvisited.pop(current.station_id))
            for station_id, overall_time in unvisited.items():
                if overall_time == min(unvisited.values()):
                    next_station = station_id
            # latest = current
            current = self.getStation(next_station)

        # return visited[-1]

        def plot_route(route):
            coordinates_limits = dict(zip(['min_lat', 'max_lat', 'min_long', 'max_long'], [1000, -1000, 1000, -1000]))
            latest_line_colour = None
            getLineColour = lambda line_id: '#999999' if line_id is None else str('#' + lines[line_id]['colour'])
            getLineName = lambda line_id: None if line_id is None else str(lines[line_id]['name'])
            ax = plt.subplot()

            for r in range(1,
                           len(route)):  # loop through a list of dictionaries, one for each station on the
                # selected route
                station1 = self.getStation(route[r - 1]['station_id'])
                station2 = self.getStation(route[r]['station_id'])
                connection = self.getConnectionBetween(station1, station2)
                self.getCoordinates(connection, station1.station_id)

                if True:
                    if connection.coordinates['lat_from'] > coordinates_limits['max_lat']:
                        coordinates_limits['max_lat'] = connection.coordinates['lat_from']
                    if connection.coordinates['lat_from'] < coordinates_limits['min_lat']:
                        coordinates_limits['min_lat'] = connection.coordinates['lat_from']
                    if connection.coordinates['long_from'] > coordinates_limits['max_long']:
                        coordinates_limits['max_long'] = connection.coordinates['long_from']
                    if connection.coordinates['long_from'] < coordinates_limits['min_long']:
                        coordinates_limits['min_long'] = connection.coordinates['long_from']
                    if connection.coordinates['lat_to'] > coordinates_limits['max_lat']:
                        coordinates_limits['max_lat'] = connection.coordinates['lat_to']
                    if connection.coordinates['lat_to'] < coordinates_limits['min_lat']:
                        coordinates_limits['min_lat'] = connection.coordinates['lat_to']
                    if connection.coordinates['long_to'] > coordinates_limits['max_long']:
                        coordinates_limits['max_long'] = connection.coordinates['long_to']
                    if connection.coordinates['long_to'] < coordinates_limits['min_long']:
                        coordinates_limits['min_long'] = connection.coordinates['long_to']

                line_colour = getLineColour(connection.line)
                if line_colour == latest_line_colour:
                    line_name = None
                else:
                    line_name = getLineName(connection.line)
                latest_line_colour = line_colour
                plt.plot([connection.coordinates['long_from'], connection.coordinates['long_to']],
                         [connection.coordinates['lat_from'], connection.coordinates['lat_to']], marker='o',
                         linestyle='--',
                         color=line_colour, label=line_name)

                ax.annotate(station1.name, xy=(connection.coordinates['long_from'], connection.coordinates['lat_from']),
                            xytext=(
                                connection.coordinates['long_from'] + 0.002,
                                connection.coordinates['lat_from'] - 0.002))

                ax.annotate(station2.name, xy=(connection.coordinates['long_to'], connection.coordinates['lat_to']),
                            xytext=(
                                connection.coordinates['long_to'] + 0.002, connection.coordinates['lat_to'] - 0.002))

            ax.set_xticks(
                [-0.60, -0.55, -0.50, -0.45, -0.40, -0.35, -0.30, -0.25, -0.20, -0.15, -0.10, -0.05, 0, 0.05, 0.10,
                 0.15, 0.20])

            ax.set_yticks([51.40, 51.45, 51.50, 51.55, 51.60, 51.65, 51.70])
            ax.set_xlim((coordinates_limits['min_long'] - 0.02), (coordinates_limits['max_long'] + 0.02))
            ax.set_ylim((coordinates_limits['min_lat'] - 0.02), (coordinates_limits['max_lat'] + 0.02))
            plt.xlabel('Longitude')
            plt.ylabel('Latitude')
            plt.legend()

            plt.show()

        plot_route(route=routes[end.station_id])
        return 'from: {} to: {}, duration: approximately {} minutes'.format(start.name, end.name, visited[-1])


class CSV:
    @staticmethod
    def importData(file_name, list_name):
        with open(file_name, mode='r') as csv_file:
            csv_reader = csv.DictReader(csv_file)
            for row in csv_reader:
                list_name.append(row)
            csv_file.close()

    @staticmethod
    def convertStringToInt(list_name, column):
        for li in list_name:
            a = int(li[column])
            li[column] = a

    @staticmethod
    def convertStringToFloat(list_name, column):
        for li in list_name:
            a = float(li[column])
            li[column] = a

    @staticmethod
    def getStationAttributeFromId(station_id, attribute_name):
        for station_info in stations:
            if station_info['hub_id'] == station_id:
                return station_info[attribute_name]

    @staticmethod
    def getStationIdFromName(station_name):
        for station_info in stations:
            if station_info['name'] == station_name:
                return station_info['hub_id']


stations = []
connections = []
linesList = []

CSV.importData('stations.csv', stations)
CSV.importData('connections.csv', connections)
CSV.convertStringToInt(stations, 'id')
CSV.convertStringToFloat(stations, 'latitude')
CSV.convertStringToFloat(stations, 'longitude')
CSV.convertStringToInt(connections, 'station1')
CSV.convertStringToInt(connections, 'station2')
CSV.convertStringToInt(connections, 'line')
CSV.convertStringToInt(connections, 'time')
CSV.importData('lines.csv', linesList)
CSV.convertStringToInt(linesList, 'line')

lines = {}
for i in linesList:
    for j in range(1, 14):
        if i['line'] == j:
            lines[j] = i

master_data = []

for i in range(len(stations)):
    stations[i]['hub_id'] = stations[i].pop('id')

for i in range(0, len(connections)):
    temp = {}
    for j in range(0, len(stations)):
        if connections[i]['station1'] == stations[j]['hub_id']:
            temp = connections[i] | stations[j]
    master_data.append(temp)

for i in range(len(master_data)):
    master_data[i]['connection_id'] = i

all_stations = {}
all_connections = {}
for i in range(len(master_data)):
    all_stations[tuple([master_data[i]['station1'], master_data[i]['line']])] = Station(master_data[i]['name'],
                                                                                        master_data[i]['station1'],
                                                                                        tuple(
                                                                                            [master_data[i]['station1'],
                                                                                             master_data[i]['line']]),
                                                                                        master_data[i]['latitude'],
                                                                                        master_data[i]['longitude'])

    all_stations[tuple([master_data[i]['station2'], master_data[i]['line']])] = Station(CSV.getStationAttributeFromId(
        master_data[i]['station2'], 'name'), master_data[i]['station2'], tuple(
        [master_data[i]['station2'], master_data[i]['line']]), CSV.getStationAttributeFromId(master_data[i]['station2'],
                                                                                             'latitude'),
        CSV.getStationAttributeFromId(master_data[i]['station2'], 'longitude'))

    all_connections[i] = Connection(master_data[i]['connection_id'],
                                    tuple([master_data[i]['station1'], master_data[i]['line']]),
                                    tuple([master_data[i]['station2'], master_data[i]['line']]), master_data[i]['time'],
                                    master_data[i]['line'])

# connect class Station with class Connection by filling station.neighbours and station.connections:
for i in range(len(master_data)):
    station_to_update = all_stations[tuple([master_data[i]['station1'], master_data[i]['line']])]
    station_to_update2 = all_stations[tuple([master_data[i]['station2'], master_data[i]['line']])]
    station_to_update.connections.append(i)
    station_to_update2.connections.append(i)
    station_to_update.neighbours.append(tuple([master_data[i]['station2'], master_data[i]['line']]))
    station_to_update2.neighbours.append(tuple([master_data[i]['station1'], master_data[i]['line']]))

# create connections representing interchanges at hubs(= stations with more than one line):
keys = range(1, len(stations) + 2)
values = [[] for i in keys]
hubs = dict(zip(keys, values))

for id_tuple, station in all_stations.items():
    hubs[id_tuple[0]].append(id_tuple)
i = 1000
time_to_change_lines = 0  # educated guess :-)
for hub in hubs.values():  # hub example: 1: [[1, 10], [1, 6], [1, 9]]
    for station in hub:  # station example: [1, 10]
        for s in hub:
            if station != s:
                all_stations[station].neighbours.append(s)
                all_stations[station].connections.append(i)
                all_connections[i] = Connection(i, station, s, time_to_change_lines, None)
                i += 1

# call the findRoute function
print(Graph().findRoute('South Wimbledon', 'Sloane Square'))